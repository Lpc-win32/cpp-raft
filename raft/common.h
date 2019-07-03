#pragma once

#include <string>
#include <cstdint>
#include <stdio.h>

#include "errors.h"

namespace raft {

const int DEFAULT_CHARS_LEN = 1024;

typedef uint32_t RaftError;

const uint64_t NONE    = 0;
const uint64_t NOLIMIT = UINT64_MAX;

typedef uint64_t StateType;
const StateType StateFollower     = 0;
const StateType StateCandidate    = 1;
const StateType StateLeader       = 2;
const StateType StatePreCandidate = 3;
const StateType numStates         = 4;

typedef int ReadOnlyOption;
const ReadOnlyOption ReadOnlySafe       = 0;
const ReadOnlyOption ReadOnlyLeaseBased = 1;

typedef std::string CampaignType;
const CampaignType CampaignPreElection = "CampaignPreElection";
const CampaignType CampaignElection    = "CampaignElection";
const CampaignType CampaignTransfer    = "CampaignTransfer";

}; // end namespace raft