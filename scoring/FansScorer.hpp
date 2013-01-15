/*
 * FansScorer.h
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#pragma once
#ifndef FANSSCORER_H_
#define FANSSCORER_H_

#include "Scorer.cpp"

namespace scoring {

class FansScorer : public Scorer {
public:
	FansScorer(double threshold)
		: Scorer(threshold)
	{}
	~FansScorer() {}

	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;
};

}

#endif /* FANSSCORER_H_ */
