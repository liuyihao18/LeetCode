// 2255_统计是给定字符串前缀的字符串数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        string_view sv(s);
        int result = 0;
        for (const string& word : words) {
            if (word.size() <= sv.size() && word == sv.substr(0, word.size())) {
                result++;
            }
        }
        return result;
    }
};
