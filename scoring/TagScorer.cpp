#include "TagScorer.hpp"

namespace scoring {

double
TagScorer::score(UserSearchQuery &query_obj, const input_t input) {
	double wdf_wt = 1.0;
	double wdf_sum = 0;
	query_weight_t &query_weight = query_obj.m_query_weight;
	query_expansion_t &query_expansion = query_obj.m_query_expansion;
	query_weight_t query_expansion_wt;
	unsigned tag_num_in_query = query_obj.m_tag_num_in_query;

    if (query_weight.find(input.matching->first) != query_weight.end()) {
        wdf_wt = query_weight[input.matching->first];
    }
    wdf_wt = wdf_wt * input.matching->second;

    string query_expanded = input.matching->first;
    if (query_expansion.find(input.matching->first) != query_expansion.end()) {
        query_expanded = query_expansion[input.matching->first];
    }

    if (query_expansion_wt.find(query_expanded) == query_expansion_wt.end()) {
        query_expansion_wt.insert(query_weight_t::value_type(query_expanded,wdf_wt));
        wdf_sum += wdf_wt;
    } else {
        double wt_ex = query_expansion_wt[query_expanded];
        if (wt_ex < wdf_wt) {
            query_expansion_wt[query_expanded] = wdf_wt;
            wdf_sum += (wdf_wt - wt_ex);
        }
    }

    double max_tag_value = 0.0;
    if(tag_num_in_query< 3){
        max_tag_value = tag_num_in_query* 3;
    }else if(tag_num_in_query< 8){
        max_tag_value = tag_num_in_query* 2;
    }else{
        max_tag_value = tag_num_in_query* 1.5;
    }

    double tag_value = 0; 
    if(max_tag_value > 0){
        tag_value = wdf_sum/max_tag_value;
    }
    tag_value = (tag_value<1)?tag_value:1; 
    double tag_score = tag_value * 300;

	return tag_score;
}

double
TagScorer::score_loose(UserSearchQuery &query_obj, const input_t input) {
	double wdf_sum = 0;
	query_weight_t &query_weight = query_obj.m_query_weight;
	query_expansion_t &query_expansion = query_obj.m_query_expansion;
	query_weight_t query_expansion_wt;
	unsigned tag_num_in_query = query_obj.m_tag_num_in_query;

	tag_num_in_query = tag_num_in_query - query_expansion.size();
	if (tag_num_in_query <= 0) {
		tag_num_in_query = 1;
	}

	double wdf_wt = 1.0;
	if (query_weight.find(input.matching->first) != query_weight.end()) {
		wdf_wt = query_weight[input.matching->first];
	}
	wdf_wt = wdf_wt * input.matching->second;

	string query_expanded = input.matching->first;
	if (query_expansion.find(input.matching->first) != query_expansion.end()) {
		query_expanded = query_expansion[input.matching->first];
	}

	if (query_expansion_wt.find(query_expanded) == query_expansion_wt.end()) {
		query_expansion_wt.insert(
				query_weight_t::value_type(query_expanded, wdf_wt));
		wdf_sum += wdf_wt;
	} else {
		double wt_ex = query_expansion_wt[query_expanded];
		if (wt_ex < wdf_wt) {
			query_expansion_wt[query_expanded] = wdf_wt;
			wdf_sum += (wdf_wt - wt_ex);
		}
	}

	double max_tag_value = 0.0;
	if(tag_num_in_query< 3){
		max_tag_value = tag_num_in_query* 3;
	}else if(tag_num_in_query< 8){
		max_tag_value = tag_num_in_query* 2;
	}else{
		max_tag_value = tag_num_in_query* 1.5;
	}

	double tag_value = 0;
	if(max_tag_value > 0){
		tag_value = wdf_sum/max_tag_value;
	}
	tag_value = (tag_value<1)?tag_value:1;
	double tag_score = tag_value * 200;
	if (tag_score < 50){
		return 0;
	}

	return tag_score;
}

double
TagScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

}
