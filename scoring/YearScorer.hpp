/*
 * YearScorer.h
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#ifndef YEARSCORER_H_
#define YEARSCORER_H_

#include "Scorer.cpp"

namespace scoring {

class YearScorer : public Scorer{
public:
	YearScorer(double threshold)
		: Scorer(threshold)
	{}
	~YearScorer() {}

	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;
};

} /* namespace scoring */
#endif /* YEARSCORER_H_ */
