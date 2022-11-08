// 1684_统计一致字符串的数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s(allowed.begin(), allowed.end());
        int result = 0;
        for (const auto& word : words) {
            bool allow = true;
            for (auto c : word) {
                if (!s.count(c)) {
                    allow = false;
                    break;
                }
            }
            if (allow) result++;
        }
        return result;
    }
};
