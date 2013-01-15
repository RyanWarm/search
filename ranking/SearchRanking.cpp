#include "SearchRanking.h"
#include <iostream>
#include <fstream>

using namespace std;

SearchRanking::SearchRanking()
{
	this->init();
}

void
SearchRanking::init()
{
	string config_file = "config_ranking.ini";
	ifstream ifs(config_file.data());
	if( ifs.is_open() == false ) {
		return;
	}
	string line;
	while( getline( ifs, line ) ) {
		size_t pos = line.find(" = ");
		if( pos == string::npos ) {
			continue;
		}

		string property = line.substr( 0, pos );
		pos += 3;
		if( pos >= line.size() ) {
			continue;
		}

		if( property == "threshold_number_source" ) {
			m_num_threshold = atoi( line.data() + pos );
			continue;
		}

		if( property == "threshold_score" ) {
			m_score_threshold = atof( line.data() + pos );
			continue;
		}
	}
}

void
SearchRanking::blending(list<UserSearchItem*> &user_list)
{
	map<UserSearchItem::user_source_t, size_t> source_count;
	SearchRanking::clear_source_count(source_count);
	list<UserSearchItem*> result;

	UserSearchItem::user_source_t preSrc = UserSearchItem::SOURCE_MAX;
	list<UserSearchItem*>::iterator index = user_list.begin();
	while( index != user_list.end() ) {
		UserSearchItem::user_source_t curSrc = (**index).get_source();
		double curSco = (**index).get_score();
		if( curSco < m_score_threshold ){
			break;
		}

		if( curSrc == preSrc && source_count[curSrc] == m_num_threshold ){
			++index;
			continue;
		}

		//insert into result list
		list<UserSearchItem*>::iterator tmpIndex = index;
		++index;
		result.push_back(*tmpIndex);
		user_list.erase(tmpIndex);

		if( curSrc != preSrc ) {
			SearchRanking::clear_source_count(source_count);
			index = user_list.begin();
			preSrc = curSrc;
		}
		source_count[curSrc]++;
	}

	//merge two lists
	result.merge(user_list);
	user_list = result;

	result.clear();
}

void
SearchRanking::clear_source_count(map<UserSearchItem::user_source_t, size_t> &sources) {
	size_t num;
	for( num = UserSearchItem::SOURCE_WEIBO; num < UserSearchItem::SOURCE_MAX; num++ ) {
		sources[(UserSearchItem::user_source_t)num] = 0;
	}
}


