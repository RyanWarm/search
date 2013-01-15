/*
 * ComPosMatchScorer.h
 *
 *  Created on: Jan 14, 2013
 *      Author: zicheng
 */

#ifndef COMPOSMATCHSCORER_H_
#define COMPOSMATCHSCORER_H_

#include "Scorer.cpp"

namespace scoring {

class ComPosMatchScorer : public Scorer {
public:
	ComPosMatchScorer(double score_threshold)
		: Scorer(score_threshold)
	{}
	~ComPosMatchScorer() {}

	double score(UserSearchQuery &query_obj, const input_t input) const;
	double filter(const double score) const;
};

} /* namespace scoring */
#endif /* COMPOSMATCHSCORER_H_ */
