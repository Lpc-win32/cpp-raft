#include "util.h"

uint64_t raft::raft_min(uint64_t a, uint64_t b)
{
    return a > b ? b : a;
}

uint64_t raft::raft_max(uint64_t a, uint64_t b)
{
    return a > b ? a : b;
}

bool raftpb::isLocalMsg(raftpb::MessageType msgt)
{
    return msgt == raftpb::MsgHup || msgt == raftpb::MsgBeat || msgt == raftpb::MsgUnreachable ||
		msgt == raftpb::MsgSnapStatus || msgt == raftpb::MsgCheckQuorum;
}

bool raftpb::isResponseMsg(raftpb::MessageType msgt)
{
    return msgt == raftpb::MsgAppResp || msgt == raftpb::MsgVoteResp || msgt == raftpb::MsgHeartbeatResp ||
        msgt == raftpb::MsgUnreachable || msgt == raftpb::MsgPreVoteResp;
}

raftpb::MessageType raftpb::voteRespMsgType(raftpb::MessageType msgt)
{
    switch msgt {
	case raftpb::MsgVote:
		return raftpb::MsgVoteResp;
	case raftpb::MsgPreVote:
		return raftpb::MsgPreVoteResp;
	default:
		throw raft::NOT_A_VOTE_MSG;
	}
}

size_t raftpb::payloadSize(raftpb::Entry e)
{
    return e.data.length;
}

std::vector<raftpb::Entry> raftpb::limitSize(std::vector<raftpb::Entry> vEntry, uint64_t maxSize)
{
    if (vEntry.size() == 0) {
        return vEntry;
    }
    std::vector<raftpb::Entry> retv;
    for int limit = 0; limit < vEntry.size(); ++limit {
        size += sizeof(vEntry[limit])
        if ((uint64_t)size > maxSize) {
            break;
        }
        retv.push_back(vEntry[limit])
    }
    return retv;
}