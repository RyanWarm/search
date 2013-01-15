/*
 * PosMatchScorer.h
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#pragma once
#ifndef POSMATCHSCORER_H_
#define POSMATCHSCORER_H_

#include "Scorer.cpp"

namespace scoring {

class PosMatchScorer : public Scorer {
public:
	PosMatchScorer(double score_threshold)
		: Scorer(score_threshold)
	{}
	~PosMatchScorer() {}
	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;

};

}

#endif /* POSMATCHSCORER_H_ */
