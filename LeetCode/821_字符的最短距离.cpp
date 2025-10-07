// 821_×Ö·ûµÄ×î¶Ì¾àÀë.cpp
#include "stdafx.h"
ustd

#define ABS(x, y) static_cast<int>(x < y ? y - x : x - y)

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<size_t> pos;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                pos.push_back(i);
            }
        }
        vector<int> answer;
        size_t curr_pos_i = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (curr_pos_i + 1 < pos.size() && ABS(i, pos[curr_pos_i]) > ABS(i, pos[curr_pos_i + 1])) {
                curr_pos_i++;
            }
            answer.push_back(ABS(i, pos[curr_pos_i]));
        }
        return answer;
    }
};
