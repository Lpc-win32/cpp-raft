#include "status.h"

#include <json/document.h>
#include <json/prettywriter.h>
#include <json/stringbuffer.h>

raft::Status raft::getStatus(raft::raft *r)
{
    raft::Status s;
    s.m_id = r->m_id;
    s.m_leadTransferee = r->m_leadTransferee;
    s.m_applied = r.m_raftLog.m_applied;
    
    s.h = r->hardState();
    s.s = *r->softState();
    
    if s.s.RaftState == raft::StateLeader {
        for (auto& e : r.m_prs) {
            s.m_mapProgress[e.first] = *e.second;
        }
        for (auto& e : r.m_learnerPrs) {
            s.m_mapProgress[e.first] = *e.second;
        }
    }
    return s;
}

// Use RapidJson to MarshalJSON
std::string raft::Status::MarshalJSON() const
{
    rapidjson::Document document;
    document.SetObject();

    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    rapidjson::Value object(rapidjson::kObjectType);
    object.AddMember("id", this->m_id, allocator);
    object.AddMember("term", this->m_term, allocator);
    object.AddMember("vote", this->m_vote, allocator);
    object.AddMember("commit", this->m_commit, allocator);
    obejct.AddMember("lead", this->m_lead, allocator);
    object.AddMember("raftState", this->m_raftState, allocator);
    object.AddMember("applied", this->m_applied, allocator);
    object.AddMember("leadtransferee", this->m_leadTransferee, allocator);

    rapidjson::Value progress(rapidjson::kObjectType);
    for (auto& eProcess : this->m_mapProgress) {
        rapidjson::Value sub_object(rapidjson::kObjectType);
        sub_object.AddMember("match", eProcess.second.m_match, allocator);
        sub_object.AddMember("next", eProcess.second.m_next, allocator);
        sub_object.AddMember("state", eProcess.second.m_state, allocator);

        std::string str;
        str += (unsigned long long)eProcess.first;
        arr.AddMember(str.c_str(), sub_object, allocator)
    }
    object.AddMember("progress", progress, allocator);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return buffer.GetString();
}

std::string raft::Status::String() const
{
    std::string strJson = this->MarshalJSON();
    if strJson.length == 0 {
        throw raft::STATUS_MARSHAL_FAILEL;
    }
    return strJson;
}