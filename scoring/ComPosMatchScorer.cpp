/*
 * ComPosMatchScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include "ComPosMatchScorer.hpp"

namespace scoring {

double
ComPosMatchScorer::score(UserSearchQuery &query_obj, const input_t input) const {
    double comp_pos_match_wt= 0.0;
	std::map<Xapian::termpos,int> pos_match;

	std::vector<Xapian::termpos> pos_list = input.pos_list;
	for (size_t i = 0; i < pos_list.size(); i++) {
		if (pos_match.find(pos_list[i]) != pos_match.end()) {
			if (pos_match[pos_list[i]] == 0) {
				comp_pos_match_wt = 1.0;
				break;
			}
		}
		pos_match.insert(std::pair<Xapian::termpos,int>(pos_list[i],1));
	}

	double comp_pos_match_score = comp_pos_match_wt*50;

	return comp_pos_match_score;
}

double
ComPosMatchScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

} /* namespace scoring */
