// 953_—È÷§Õ‚–«”Ô¥ µ‰.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(128, -1);
        for (size_t i = 0; i < order.size(); i++) {
            dict[order[i]] = static_cast<int>(i);
        }
        auto cmp = [&](const string& s1, const string& s2) {
            size_t n = min(s1.size(), s2.size());
            for (size_t i = 0; i < n; i++) {
                if (dict[s1[i]] < dict[s2[i]]) {
                    return -1;
                }
                else if(dict[s1[i]] > dict[s2[i]]) {
                    return 1;
                }
            }
            if (s1.size() < s2.size()) {
                return -1;
            }
            else if (s1.size() > s2.size()) {
                return 1;
            }
            else {
                return 0;
            }
        };
        for (size_t i = 0; i + 1 < words.size(); i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            if (cmp(word1, word2) > 0) {
                return false;
            }
        }
        return true;
    }
};
