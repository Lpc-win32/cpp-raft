#pragma once

#include <map>

#include "common.h"
#include "raftpb/raft.pb.h"

namespace raft {

class Status {
    public:
        std::string MarshalJSON() const;
        std::string String() const;

        uint64_t m_s;
        uint64_t m_id;
        uint64_t m_applied;
        uint64_t m_leadTransferee;
        std::map<uint64_t, tracker::Progress> m_mapProgress;

        SoftState s;
        raftpb::HardState h;
}; // end class Status

// getStatus gets a copy of the current raft status.
Status getStatus(raft::raft *r);

}; // end namespace raft