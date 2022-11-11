#pragma once

#include "search/definitions.h"
#include "search/driver.h"
#include "search_manager/worker_api.h"
#include "types.h"
#include "utils.h"

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class ShardManager;

class Shard {

  public:
    Shard(ShardManager* manager, search::DBShard shard_info)
        : _shard_info(shard_info), _shard_id(shard_info.shard_id), _db_id(shard_info.db_id){};

    ~Shard() = default;

    // Assign a worker for this shard.
    RetCode AssignWorker(Worker* worker);

    // AddFeatures to this shard, delegate to worker client to do the actual storage.
    RetCode AddFeatures(std::vector<Feature> fts);

    // SearchFeature in this shard, delegate to worker client to do the actual search.
    std::vector<FeatureScore> SearchFeature(const Feature& query, int topk);

    RetCode Close();

    // check the shard has been assigned worker or not.
    inline bool HasWorker() { return _worker == nullptr; };

    // check the shard is closed or not.
    inline bool IsClosed() { return _shard_info.is_closed; };

    inline std::string GetShardID() { return _shard_id; };

    inline search::DBShard GetShardInfo() { return _shard_info; };

  private:
    search::DBShard _shard_info;

    std::string _shard_id;
    std::string _db_id;

    std::string _worker_id;
    Worker* _worker = nullptr;

    ShardManager* _shard_mgr = nullptr;
};
