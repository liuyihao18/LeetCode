// 187_ÖØ¸´µÄDNAÐòÁÐ.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) {
            return vector<string>();
        }
        unordered_map<string, size_t> ms;
        for (size_t i = 0; i < s.size() - 9; i++) {
            ms[s.substr(i, 10)]++;
        }
        vector<string> result;
        for_each(ms.begin(), ms.end(), [&](const pair<string, size_t>& p) {
            if (p.second > 1) {
                result.push_back(p.first);
            }
            });
        return result;
    }
};