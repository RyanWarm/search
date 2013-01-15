/*
 * UserScorer.h
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#ifndef USERSCORER_H_
#define USERSCORER_H_

#include "Scorer.cpp"

namespace scoring {

class UserScorer : public Scorer {
public:
	UserScorer(double threshold)
		: Scorer(threshold)
	{}
	virtual ~UserScorer() {}

	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;
};

} /* namespace scoring */
#endif /* USERSCORER_H_ */
