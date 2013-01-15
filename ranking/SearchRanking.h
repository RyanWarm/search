#pragma once
#include <list>
#include <map>
#include "UserSearchItem.hpp"

using namespace std;

#ifndef SEARCHRANKING_H_
#define SEARCHRANKING_H_

class SearchRanking {
private:
	size_t m_num_threshold;
	double m_score_threshold;

	void init();

public:
	SearchRanking();
	virtual ~SearchRanking() {};

	void blending(list<UserSearchItem*> &user_vector);
	void clear_source_count(map<UserSearchItem::user_source_t, size_t> &sources);
};

#endif /* SEARCHRANKING_H_ */
