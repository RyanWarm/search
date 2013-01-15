/*
 * PosMatchScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include "PosMatchScorer.hpp"

namespace scoring {

double
PosMatchScorer::score(UserSearchQuery &query_obj, const input_t input) const {
	double pos_sum = 0;
	double wdf_wt = 1.0;

	query_expansion_t &query_expansion = query_obj.m_query_expansion;
	unsigned pos_num_in_query = query_obj.m_pos_num_in_query;
	query_weight_t pos_expansion_wt;

	string pos_expanded = input.matching->first;
	if (query_expansion.find(input.matching->first) != query_expansion.end()) {
		pos_expanded = query_expansion[input.matching->first];
	}

	if (pos_expansion_wt.find(pos_expanded) == pos_expansion_wt.end()) {
		pos_expansion_wt.insert(query_weight_t::value_type(pos_expanded,wdf_wt));
		pos_sum += wdf_wt;
	} else {
		double wt_ex = pos_expansion_wt[pos_expanded];
		if (wt_ex < wdf_wt) {
			pos_expansion_wt[pos_expanded] = wdf_wt;
			pos_sum += (wdf_wt - wt_ex);
		}
	}

    double pos_match_score = 0;
    if(pos_sum > 0) {
        pos_match_score = pos_sum * 100 / pos_num_in_query;
    }

	return pos_match_score;
}

double
PosMatchScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

}
