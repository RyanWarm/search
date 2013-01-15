/*
 * WorkScorer.hpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#ifndef WORKSCORER_HPP_
#define WORKSCORER_HPP_

#include "Scorer.cpp"

namespace scoring {

class WorkScorer : public Scorer {
public:
	WorkScorer(double threshold)
		: Scorer(threshold)
	{}
	~WorkScorer() {}

	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;
};

} /* namespace scoring */
#endif /* WORKSCORER_HPP_ */
