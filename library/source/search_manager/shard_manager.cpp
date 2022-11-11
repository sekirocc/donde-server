#include "search_manager/shard_manager.h"

#include "search/definitions.h"
#include "types.h"
#include "utils.h"

#include <spdlog/spdlog.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Shard
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Assign a worker for this shard.
RetCode Shard::AssignWorker(Worker* worker) {
    if (worker != nullptr) {
        _worker = worker;
        _worker_id = worker->GetWorkerID();
    }

    _worker->ServeShard(_shard_info);

    return RetCode::RET_OK;
};

// AddFeatures to this shard, delegate to worker client to do the actual storage.
RetCode Shard::AddFeatures(std::vector<Feature> fts) {
    if (_worker == nullptr) {
        spdlog::error("shard has no worker, AssignWorker first.");
        return RetCode::RET_ERR;
    }
    // delegate to worker.
    auto ret = _worker->AddFeatures(_db_id, _shard_id, fts);
    if (ret == RetCode::RET_OK) {
        _shard_info.used += fts.size();
    }
    return {};
};

// SearchFeature in this shard, delegate to worker client to do the actual search.
std::vector<FeatureScore> Shard::SearchFeature(const Feature& query, int topk) {
    return _worker->SearchFeature(_shard_info.db_id, query, topk);
};

RetCode Shard::Close() {
    _shard_mgr->CloseShard(_db_id, _shard_id);
    _worker->CloseShard(_db_id, _shard_id);

    _shard_info.is_closed = true;

    return {};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ShardManager
////////////////////////////////////////////////////////////////////////////////////////////////////////////

ShardManager::ShardManager(search::Driver& driver) : _driver(driver) { load_db_shards(); };

std::tuple<Shard*, bool> ShardManager::FindOrCreateWritableShard(std::string db_id,
                                                                 uint64 fts_count) {
    // if db_id not exists, this will throw 404.
    auto shards = ListShards(db_id);

    for (auto shard : shards) {
        if (!shard->IsClosed()) {
            auto shard_info = shard->GetShardInfo();
            if (shard_info.capacity - shard_info.used > fts_count) {
                return {shard, false};
            } else {
                // close now?
                shard->Close();
                break;
            }
        }
    }

    // create new shard;
    search::DBShard shard_info{
        .db_id = db_id,
        .is_closed = false,
        .capacity = search::DEFAULT_SHARD_CAPACITY,
        .used = 0,
    };

    std::string shard_id = CreateShard(shard_info);
    shard_info.shard_id = shard_id;

    // shards for db_id must exists.
    Shard* shard = new Shard{this, shard_info};
    _db_shards[db_id].push_back(shard);

    return {shard, true};
};

RetCode AssignWorkerToShard(Shard* shard, Worker* worker) {
    shard->AssignWorker(worker);
    return RetCode::RET_OK;
};

std::vector<search::DBItem> ShardManager::ListUserDBs() {
    std::vector<search::DBItem> dbs;

    for (auto it = _user_dbs.begin(); it != _user_dbs.end(); it++) {
        dbs.push_back(it->second);
    }

    return dbs;
};

std::vector<Shard*> ShardManager::ListShards(std::string db_id) {
    auto iter = _db_shards.find(db_id);
    if (iter == _db_shards.end()) {
        throw "db_id not exists";
    }
    return iter->second;
};

RetCode ShardManager::CloseShard(std::string db_id, std::string shard_id) {
    _driver.CloseShard(db_id, shard_id);
    return {};
};

std::string ShardManager::CreateShard(search::DBShard shard_info) {
    std::string shard_id = _driver.CreateShard(shard_info.db_id, shard_info);
    return shard_id;
};

RetCode ShardManager::load_db_shards() {
    std::vector<search::DBItem> user_dbs = _driver.ListDBs();

    for (auto& db : user_dbs) {
        // _user_dbs[db.db_id] = db;
        _user_dbs.insert({db.db_id, db});

        std::vector<Shard*> shards;
        std::vector<search::DBShard> shard_infos = _driver.ListShards(db.db_id);
        for (auto& shard_info : shard_infos) {
            shards.push_back(new Shard{this, shard_info});

            // this will be more efficient?
            // _db_shards[db.db_id].push_back(new Shard{this, shard_info});
        }

        _db_shards.insert({db.db_id, shards});
    }

    return {};
};
