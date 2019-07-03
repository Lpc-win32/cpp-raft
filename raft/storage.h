#pragma once

#include <vector>
#include <mutex>

#include "common.h"
#include "raftpb/raft.pb.h"

namespace raft {

class Storage {
    public:
        virtual RaftError InitialState(raftpb::HardState *destH, raftpb::ConfState *destC) = 0;
        virtual std::vector<raftpb::Entry> Entries(uint64_t lo, uint64_t hi, uint64_t maxSize) = 0;
        virtual RaftError Term(uint64_t i, uint64_t *dest) = 0;
        virtual RaftError LastIndex(uint64_t *dest) = 0;
        virtual RaftError FirstIndex(uint64_t *dest) = 0;
        virtual RaftError Snapshot(raftpb::Snapshot *s) = 0;
};

class MemoryStorage : public Storage {

};

}; // end namespace raft