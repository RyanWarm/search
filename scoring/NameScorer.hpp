/*
 * NameScorer.hpp
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#ifndef NAMESCORER_HPP_
#define NAMESCORER_HPP_

#include "Scorer.cpp"

namespace scoring {

class NameScorer : public Scorer{
public:
	NameScorer(double threshold)
		: Scorer(threshold)
	{}
	~NameScorer() {}

	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;
};

} /* namespace scoring */
#endif /* NAMESCORER_HPP_ */
