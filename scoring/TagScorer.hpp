/*
 * TagScorer.h
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#pragma once
#ifndef TAGSCORER_H_
#define TAGSCORER_H_

#include "Scorer.cpp"

namespace scoring {

class TagScorer : public Scorer
{
public:
	TagScorer(double score_threshold)
		: Scorer(score_threshold)
	{}
	~TagScorer() {}
	double score(UserSearchQuery &query_obj, const input_t input);
	double score_loose(UserSearchQuery &query_obj, const input_t input);
	double filter(const double score) const;

};

}

#endif /* TAGSCORER_H_ */
