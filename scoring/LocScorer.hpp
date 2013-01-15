/*
 * LocScorer.h
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#ifndef LOCSCORER_H_
#define LOCSCORER_H_

#include "Scorer.cpp"

namespace scoring {

class LocScorer : public Scorer{
public:
	LocScorer(double threshold)
		: Scorer(threshold)
	{}
	~LocScorer() {}

	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;
};

} /* namespace scoring */
#endif /* LOCSCORER_H_ */
