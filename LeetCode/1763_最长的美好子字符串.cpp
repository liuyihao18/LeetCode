// 1763_最长的美好子字符串.cpp
#include "custom.h"
ustd

class Solution {
    bool isBeautiful(const string& s) {
        vector<bool> counts(128, false);
        for (auto c : s) {
            counts[c] = true;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (counts[c] ^ counts[c + 'A' - 'a']) {
                return false;
            }
        }
        return true;
    }
public:
    string longestNiceSubstring(string s) {
        string result;
        for (size_t i = 0; i < s.size(); i++) {
            for (size_t l = 1; i + l <= s.size(); l++) {
                string temp = s.substr(i, l);
                if (isBeautiful(temp) && temp.size() > result.size()) {
                    result = std::move(temp);
                }
            }
        }
        return result;
    }
};
