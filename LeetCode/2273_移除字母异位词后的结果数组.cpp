// 2273_移除字母异位词后的结果数组.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        size_t n = words.size();
        auto iter = unique(words.begin(), words.end(), [](string a, string b) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            return a == b;
            });
        words.erase(iter, words.end());
        return words;
    }
};
