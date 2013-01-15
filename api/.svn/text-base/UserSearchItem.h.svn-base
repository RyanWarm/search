#pragma once
#include <stdint.h>

struct UserSearchItem
{
    static const uint64_t SOURCE_MAX = 128;

    typedef uint64_t user_source_t;
    uint64_t uid;
    double score;
    user_source_t source;
    
    uint64_t link_distance;
    std::string debug_str;
};
