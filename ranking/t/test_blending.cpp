#include <iostream>
#include "../RankingUtils.h"

using namespace std;

int main() {
	vector<UserSearchItem> input;
	vector<UserSearchItem> input1;
	UserSearchItem::user_source_t src;
	for( size_t i = 0; i < 30; i++ ) {
		if( i < 10 ) {
			src = 0;
		} else if( i < 20 ) {
			src = 1;
		} else {
			src = 2;
		}
		UserSearchItem item;
        item.uid = i;
        item.score = 1.0 - (double)i/100.0;
        item.source = src;
		input.push_back(item);
		input1.push_back(item);
	}

	ranking::blending(input,2);
	cout << "______final result1_________" << endl;

	vector<UserSearchItem>::iterator index;
	for( index = input.begin(); index != input.end(); ++index ) {
		cout << (*index).uid << "-------" << (*index).source << endl;
	}

	return 0;
}
