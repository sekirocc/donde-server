#include "donde/definitions.h"
#include "donde/feature_search/api.h"
#include "donde/feature_search/search_worker/api.h"
#include "donde/feature_search/search_worker/shard.h"
#include "donde/utils.h"
#include "nlohmann/json.hpp"

#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <queue>

using namespace std;

using json = nlohmann::json;

namespace donde {

namespace feature_search {

namespace search_worker {

class BruteForceSearcher : public Searcher {

  public:
    // Searcher contructor, doesn't own ShardManager and Driver, but reference to them.
    // The caller should clean ShardManager and Driver themself.
    BruteForceSearcher(ShardManager& shard_manager, Driver& driver);

    ~BruteForceSearcher() = default;

    RetCode Start() override {
        spdlog::warn("Init is not implemented by BruteForceSearch");
        return RetCode::RET_OK;
    };

    RetCode Stop() override {
        spdlog::warn("Iterminate is not implemented by BruteForceSearch");
        return RetCode::RET_OK;
    };

    RetCode TrainIndex() override {
        spdlog::warn("TrainIndex is not implemented by BruteForceSearch");
        return RetCode::RET_OK;
    };

    // ServeShards let this searcher serve these shards, typically loads shards' data into search
    // engine.
    RetCode ServeShards(const std::vector<DBShard>& shard_infos) override;

    // CloseShards close these shards, so that user cannot write to them.
    // if implementation map db with shard as 1:1, then after close the shard
    // user should call `ServeShards` for those db, so that there will be active writing shard
    // available, if not, user cannot AddFeatures to the db anymore.
    RetCode CloseShards(const std::vector<DBShard>& shard_infos) override;

    std::vector<FeatureSearchItem> SearchFeature(const std::string& db_id, const Feature& query,
                                                 size_t topk) override;

    std::vector<std::string> AddFeatures(const std::string& db_id,
                                         const std::vector<FeatureDbItem>& features) override;

    RetCode RemoveFeatures(const std::string& db_id,
                           const std::vector<std::string>& feature_ids) override;

  private:
    json _config;
    ShardManager& _shard_mgr;
    Driver& _driver;
};

} // namespace search_worker

} // namespace feature_search

} // namespace donde
