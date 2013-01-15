/*
 * NameScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include "NameScorer.hpp"

namespace scoring {

double
NameScorer::score(UserSearchQuery &query_obj, input_t input) const {
	double name_score = input.score;

	if (name_score == 1) {
		name_score = 100;
	}else if (name_score > 0.9) {
		name_score = pow(name_score,2) * 80;
	} else {
		name_score = pow(name_score,2) * 60;
	}

	return name_score;
}

double
NameScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

} /* namespace scoring */
