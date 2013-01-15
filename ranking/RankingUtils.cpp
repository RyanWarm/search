#include "RankingUtils.h"
#include <iostream>

using namespace std;

namespace ranking{

bool
blending(vector<UserSearchItem> &user_list, int kmax)
{
    vector<UserSearchItem>::iterator it = user_list.begin();
    int k = 0;
    UserSearchItem::user_source_t previous_source = 9999;
    while(it != user_list.end()){
        if(it->source != previous_source){
            previous_source = it->source;
            k = 1;
            it += 1;
            continue;
        }else{
            k += 1;
            if(k <= kmax){
                it += 1;
                continue;
            }else{
                vector<UserSearchItem>::iterator dit = it + 1;
                while(dit!= user_list.end() && dit->source==previous_source){
                    dit += 1;
                }
                if(dit == user_list.end()){
                    it += 1;
                    continue;
                }else{
                    UserSearchItem tmp = *dit;
                    *dit = *it;
                    *it = tmp;
                    k = 0;
                    previous_source = it->source;
                    it += 1;
                    continue;
                }
            }
        }
    }
    return true;
}

} //end of namespace ranking

