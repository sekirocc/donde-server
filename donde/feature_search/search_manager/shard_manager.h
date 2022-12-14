#pragma once

#include "donde/definitions.h"
#include "donde/feature_search/api.h"

// #include "spdlog/spdlog.h"

#include <iostream>
#include <unordered_map>

using namespace std;

namespace donde {

namespace feature_search {

namespace search_manager {

class Shard;
class Worker;
class ShardManager {

  public:
    virtual ~ShardManager() = default;

    virtual std::tuple<Shard*, bool> FindOrCreateWritableShard(std::string db_id, uint64 fts_count)
        = 0;

    virtual RetCode AssignWorkerToShard(Shard* shard, Worker* worker) = 0;

    virtual std::vector<DBItem> ListUserDBs() = 0;

    virtual std::vector<Shard*> ListShards(std::string db_id) = 0;

    virtual RetCode CloseShard(std::string db_id, std::string shard_id) = 0;

    virtual std::string CreateShard(DBShard shard_info) = 0;

    virtual RetCode UpdateShard(DBShard shard_info) = 0;
};
;

} // namespace search_manager
} // namespace feature_search
} // namespace donde
