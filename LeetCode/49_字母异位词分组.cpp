// 49_×ÖÄ¸ÒìÎ»´Ê·Ö×é.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> um;
        for (size_t i = 0; i < strs.size(); i++) {
            vector<int> cnt(128, 0);
            for_each(strs[i].begin(), strs[i].end(),
                [&](char c) {
                    cnt[c]++;
                }
            );
            um[cnt].push_back(strs[i]);
        }
        vector<vector<string>> results;
        transform(um.begin(), um.end(), back_inserter(results),
            [](const decltype(*um.begin())& p) {
                return p.second;
            }
        );
        return results;
    }
};
