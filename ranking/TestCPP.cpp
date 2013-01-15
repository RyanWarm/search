#include <iostream>
#include "RankingUtils.h"

using namespace std;

int main() {
	list<UserSearchItem*> input;
	list<UserSearchItem*> input1;
	UserSearchItem::user_source_t src;
	for( size_t i = 0; i < 15; i++ ) {
		if( i < 5 ) {
			src = 0;
		} else if( i < 10 ) {
			src = 1;
		} else {
			src = 2;
		}
		UserSearchItem *item = new UserSearchItem(i, 1.0-(double)i/100.0, src);
		input.push_back(item);
		input1.push_back(item);
	}

	ranking::blending(input);
	cout << "______final result1_________" << endl;

	list<UserSearchItem*>::iterator index;
	for( index = input.begin(); index != input.end(); ++index ) {
		cout << (**index).get_uid() << "-------" << (**index).get_source() << endl;
	}

	return 0;
}
