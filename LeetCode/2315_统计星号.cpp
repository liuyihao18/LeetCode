// 2315_Í³¼ÆÐÇºÅ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countAsterisks(string s) {
        bool in = false;
        int result = 0;
        for (auto c : s) {
            if (c == '|') {
                in = !in;
            }
            else if (c == '*' && !in) {
                result++;
            }
        }
        return result;
    }
};
