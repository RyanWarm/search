#include <list>
#include <vector>
#include "UserSearchSession.hpp"
#include "UserSearchWeight.hpp"
#include "api/UserSearchItem.h"
#include "ranking/RankingUtils.h"


UserSearchSession::~UserSearchSession(){
        if(m_weight){
            delete m_weight;
            m_weight = 0;
        }
    }
    
Xapian::Weight *
UserSearchSession::weighter(Xapian::Database *db) {
        if(m_weight){
            return m_weight;
        }else{
            m_weight = new UserSearchWeight(db,this);
            return dynamic_cast<Xapian::Weight *>(m_weight);
        }
    }
    
void
UserSearchSession::reset()
{
    m_stats.reset();
    m_mid_data_recorder.clear();
}
bool 
UserSearchSession::match_set_process(Xapian::MSet &matches, string &resp)
{
    UserSearchResult pb_result;
    //numbers
    pb_result.set_offset(m_query.offset());
    pb_result.set_total_estimated(matches.get_matches_estimated());
    TB_INFO("matches before cutoff:"<<m_matches_pre_cutoff);
    TB_INFO("matches count:"<<matches.get_matches_estimated());
    
    std::vector<UserSearchItem> match_vec;
    for (Xapian::MSetIterator i = matches.begin(); i != matches.end(); ++i) {
        UserSearchItem item;
        string data = i.get_document().get_data();
        item.uid = *(uint64_t*)data.data(); 
        item.score = i.get_weight(); 
        item.link_distance = 1;
        if(m_query.pb_query.has_debug() && m_query.pb_query.debug()){
            item.debug_str = m_mid_data_recorder[item.uid];
        }
        item.source = item.uid >> 56;
        TB_DEBUG("uid :"<<item.uid);
        match_vec.push_back(item);
    }
    //blending
    //ranking::blending(match_vec, 3);
    //matches
    //size_t pos = 0;
    for(std::vector<UserSearchItem>::iterator it=match_vec.begin();it!=match_vec.end();it++){
        /*
        if(pos < offset){
            ++pos;
            continue;
        }
        if(pos >= offset+count){
            break;
        }
        */
        UserSearchResult_ResultItem *item = pb_result.add_result_item();
        item->set_uid(it->uid);
        item->set_score(it->score);
        item->set_link_distance(it->link_distance);
        item->set_debug_data(it->debug_str);
    }
    pb_result.set_count(pb_result.result_item_size());
    TB_INFO("matches in range:"<<pb_result.result_item_size());

    //stats
    std::vector<SearchStats::pair_t> top_v;
    m_stats.topk(top_v,MAX_STATS_ITEMS);
    for(unsigned i=0;i<top_v.size();i++){
        const SearchStats::term_t &key = top_v[i].first;
        uint32_t value = top_v[i].second;
        UserSearchResult_StatsItem *stats = pb_result.add_stats_item();
        stats->set_stats_type(USER_STATS_NAME[m_query.task_type]);
        stats->set_stats_key(key);
        stats->set_stats_value(value);
    }
    //serialize
    if(false == pb_result.SerializeToString(&resp)){
        TB_DEBUG("serialize response failed");
        return false;
    }
    return true;
}

