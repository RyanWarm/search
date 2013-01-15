/*
 * UserScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include "UserScorer.hpp"

namespace scoring {

double
UserScorer::score(UserSearchQuery &query_obj, input_t input) const {
	double user_score = input.score;

	return user_score * 0.7;
}

double
UserScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

} /* namespace scoring */
