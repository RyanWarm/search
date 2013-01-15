/*
 * LocScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include "LocScorer.hpp"

namespace scoring {

double
LocScorer::score(UserSearchQuery &query_obj, input_t input) const {
	double loc_score = 1.0;

	return loc_score * 50;
}

double
LocScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

} /* namespace scoring */
