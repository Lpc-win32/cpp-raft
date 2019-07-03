#pragma once

#include "common.h"
#include "raftpb/raft.pb.h"

namespace raft {

uint64_t raft_min(uint64_t a, uint64_t b);
uint64_t raft_max(uint64_t a, uint64_t b);

bool isLocalMsg(raftpb::MessageType msgt);
bool isResponseMsg(raftpb::MessageType msgt);

raftpb::MessageType voteRespMsgType(raftpb::MessageType msgt);
size_t payloadSize(raftpb::Entry e);
std::vector<raftpb::Entry> limitSize(std::vector<raftpb::Entry> vEntry, uint64_t maxSize);

};