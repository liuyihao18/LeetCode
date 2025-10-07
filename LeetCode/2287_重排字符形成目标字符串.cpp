// 2287_重排字符形成目标字符串.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        map<char, int> t;
        for (auto c : target) {
            t[c]++;
        }
        int result = INT_MAX;
        for (pair<char, int> p : t) {
            result = min(result, m[p.first] / p.second);
        }
        return result;
    }
};
