#pragma once

#include "config.h"
#include "donde/feature_search/api.h"
#include "donde/feature_search/search_manager/api.h"
#include "source/feature_search/cassandra_driver.h"

// #include "spdlog/spdlog.h"

#include <iostream>
#include <unordered_map>

using namespace std;

namespace donde {
namespace feature_search {
namespace search_manager {

using WorkerPtr = shared_ptr<Worker>;

// Coordinator & Reducer
class CoordinatorImpl : public Coordinator {
  public:
    CoordinatorImpl(const json& coor_config);
    ~CoordinatorImpl();

    void Start();

    void Stop();

    // std::vector<WorkerPtr> ListWorkers();

    std::vector<DBItem> ListUserDBs();

    // AddFeatures to this db, we need find proper shard to store these fts.
    std::vector<std::string> AddFeatures(const std::string& db_id, const std::vector<Feature>& fts);

    // RemoveFeatures from this db
    RetCode RemoveFeatures(const std::string& db_id, const std::vector<std::string>& feature_ids);

    // SearchFeatures in this db.
    std::vector<FeatureSearchItem> SearchFeature(const std::string& db_id, const Feature& query,
                                            int topk);

  private:
    void initialize_workers();
    void deinitialize_workers();
    void assign_worker_for_shards();
    Worker* find_worker_for_shard(Shard* shard);

  private:
    const json& config;

    std::vector<std::string> _worker_addrs;
    std::vector<std::string> _invalid_worker_addrs;

    std::vector<WorkerPtr> _workers;

    shared_ptr<Driver> _driver;

    std::shared_ptr<ShardManager> _shard_manager;

    // spdlog::Logger& logger;
};

} // namespace search_manager
} // namespace feature_search
} // namespace donde
