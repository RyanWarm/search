/*
 * WorkScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include "WorkScorer.hpp"

namespace scoring {

double
WorkScorer::score(UserSearchQuery &query_obj, input_t input) const {
	double work_score = 0;
	unsigned wyear = input.num;

	if(wyear > 10){
		work_score = 15;
	}else if(wyear > 5){
		work_score = 10;
	}else if(wyear > 0){
		work_score = 5;
	}

	return work_score;
}

double
WorkScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

} /* namespace scoring */
