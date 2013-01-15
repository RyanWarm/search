/*
 * FansScorer.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#include <math.h>
#include "FansScorer.hpp"

namespace scoring {

double
FansScorer::score(UserSearchQuery &query_obj, input_t input) const {
	double fans_score = (double)input.num;
	if(fans_score > 10000){
		fans_score = 10000;
	}
	fans_score = pow(fans_score/10000,0.4) * 30;

	return fans_score;
}

double
FansScorer::filter(const double score) const {
	return score > this->m_score_threshold ? score : 0;
}

}
