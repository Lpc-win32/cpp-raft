#pragma once

#include <string>

namespace raft {

// util
const std::string ERR_NOT_A_VOTE_MSG = "not a vote message";

// status
const std::string ERR_STATUS_MARSHAL_FAILEL = "raft Status MarshalJSON exec failed";

// storage
const std::string ERR_COMPACTED = "requested index is unavailable due to compaction";
const std::string ERR_SNAP_OUTOFDATE = "requested index is older than the existing snapshot";
const std::string ERR_UNAVAILABLE = "requested entry at index is unavailable";
const std::string ERR_SNAPSHOT_TEMPORARILY_UNAVAILABLE = "snapshot is temporarily unavailable";

};