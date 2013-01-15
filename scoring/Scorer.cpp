#include "../UserSearchQuery.hpp"
#include <xapian.h>

using namespace std;

namespace scoring {

class Scorer
{
public:
	double m_score_threshold;
	union input_t {
		std::pair<std::string, Xapian::termcount>* matching;
		double score;
		unsigned num;
	};

public:
	Scorer(double threshold)
		: m_score_threshold(threshold)
	{}
	virtual double score(const UserSearchQuery &query_obj, const input_t input);
	virtual double score_loose(const UserSearchQuery &query_obj, const input_t input);
	virtual double filter(const double score) const = 0;

};

}
