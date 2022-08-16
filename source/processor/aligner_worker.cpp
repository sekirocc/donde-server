#include "Poco/AutoPtr.h"
#include "Poco/Logger.h"
#include "Poco/Notification.h"
#include "Poco/NotificationQueue.h"
#include "concurrent_processor.h"
#include "detector_worker.h"
#include "opencv2/opencv.hpp"
#include "openvino/openvino.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "types.h"
#include "utils.h"

#include <cassert>
#include <cmath>
#include <filesystem>
#include <iostream>
#include <memory>
#include <opencv2/core/cvdef.h>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>

using Poco::Notification;
using Poco::NotificationQueue;

using namespace Poco;

AlignerWorker::AlignerWorker(std::shared_ptr<NotificationQueue> ch) : Worker(ch) {}

AlignerWorker::~AlignerWorker() {
    // _channel.reset();
}

RetCode AlignerWorker::Init(json conf, int i, std::string device_id) {
    _name = "aligner-worker-" + std::to_string(i);
    _logger = spdlog::stdout_color_mt(_name);

    _id = i;
    _device_id = device_id;
    _conf = conf;

    return RET_OK;
}

void AlignerWorker::run() {
    for (;;) {
        Notification::Ptr pNf(_channel->waitDequeueNotification());

        if (pNf) {
            WorkMessage::Ptr msg = pNf.cast<WorkMessage>();
            if (msg) {
                if (msg->isQuitMessage()) {
                    break;
                }
                Value input = msg->getRequest();
                if (input.valueType != ValueLandmarksResult) {
                    _logger->error("AlignerWorker input value is not a ValueLandmarksResult! wrong "
                                   "valueType: {}",
                                   format(input.valueType));
                    continue;
                }
                std::shared_ptr<LandmarksResult> landmarks_result
                    = std::static_pointer_cast<LandmarksResult>(input.valuePtr);
                std::shared_ptr<AlignerResult> result = std::make_shared<AlignerResult>();

                RetCode ret = process(*landmarks_result, *result);
                _logger->debug("process ret: {}", ret);

                Value output{ValueLandmarksResult, result};
                msg->setResponse(output);
            }
        } else {
            break;
        }
    }
}

RetCode AlignerWorker::process(const LandmarksResult& landmarks_result, AlignerResult& result) {
    if (landmarks_result.face_landmarks.size() != landmarks_result.faces.size()) {
        _logger->error("faces count is not equal to face landmarks count!");
        return RetCode::RET_ERR;
    }

    for (size_t i = 0; i < landmarks_result.faces.size(); i++) {
        cv::Mat aligned
            = align_face(landmarks_result.faces.at(i), landmarks_result.face_landmarks.at(i));
        result.aligned_faces.push_back(aligned);
    }

    return RetCode::RET_OK;
}

cv::Mat AlignerWorker::align_face(const cv::Mat& face_image,
                                  const std::vector<cv::Point2f>& landmarks) {
    // left eye: landmarks[0],  landmarks[1],
    // right eye: landmarks[2],  landmarks[3],

    cv::Point2f left_eye_center
        = {(landmarks[0].x + landmarks[1].x) / 2, (landmarks[0].y + landmarks[1].y) / 2};
    cv::Point2f right_eye_center
        = {(landmarks[2].x + landmarks[3].x) / 2, (landmarks[2].y + landmarks[3].y) / 2};

    cv::Point2f center = {(left_eye_center.x + right_eye_center.x) / 2,
                          (left_eye_center.y + right_eye_center.y) / 2};

    double dx = (right_eye_center.x - left_eye_center.x);
    double dy = (right_eye_center.y - left_eye_center.y);
    double angle = atan2(dy, dx) * 180 / CV_PI;

    cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0f);
    cv::Mat warped;

    cv::warpAffine(face_image, warped, rot_mat, warped.size());

    return warped;
}
