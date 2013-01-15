/*
 * YearScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include "YearScorer.hpp"

namespace scoring {

double
YearScorer::score(UserSearchQuery &query_obj, input_t input) const {
	double year_score = 1.0;

	return year_score * 50;
}

double
YearScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

} /* namespace scoring */
