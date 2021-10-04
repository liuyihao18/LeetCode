// 482_√‹‘ø∏Ò ΩªØ.cpp
#include "custom.h"
ustd

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        istringstream is(s);
        string plain_string;
        for (auto c : s) {
            if (c != '-') {
                plain_string.push_back(toupper(c));
            }
        }
        size_t remainder = plain_string.size() % k;
        string result;
        size_t i = 0;
        if (remainder) {
            for (; i < remainder; i++) {
                result.push_back(plain_string[i]);
            }
            result.push_back('-');
        }
        while (i < plain_string.size()) {
            for (int j = 0; j < k; j++, i++) {
                result.push_back(plain_string[i]);
            }
            result.push_back('-');
        }
        if (result.size()) result.pop_back();
        return result;
    }
};