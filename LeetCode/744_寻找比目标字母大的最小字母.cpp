// 744_寻找比目标字母大的最小字母.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) {
            return letters.front();
        }
        return *upper_bound(letters.begin(), letters.end(), target);
    }
};
