// 639_½âÂë·½·¨ II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numDecodings(string s) {
        auto get_1 = [&](size_t index) {
            if (s[index] == '*') {
                return 9;
            }
            else if (s[index] >= '1' && s[index] <= '9') {
                return 1;
            }
            else {
                return 0;
            }
        };
        auto get_2 = [&](size_t index) {
            if (s[index] == '*' && s[index + 1] == '*') {
                return 15;
            }
            else if (s[index] == '*' && (s[index + 1] >= '0' && s[index + 1] <= '6')) {
                return 2;
            }
            else if (s[index] == '*' && (s[index + 1] >= '7' && s[index + 1] <= '9')) {
                return 1;
            }
            else if (s[index] == '1' && s[index + 1] == '*') {
                return 9;
            }
            else if (s[index] == '2' && s[index + 1] == '*') {
                return 6;
            }
            else if (s[index] == '1' && (s[index + 1] >= '0' && s[index + 1] <= '9')) {
                return 1;
            }
            else if (s[index] == '2' && (s[index + 1] >= '0' && s[index + 1] <= '6')) {
                return 1;
            }
            else {
                return 0;
            }
        };
        vector<size_t> result(s.size(), 0);
        if (result.size() > 0) {
            result[0] = get_1(0);
        }
        if (result.size() > 1) {
            result[1] = result[0] * get_1(1) + get_2(0);
        }
        for (size_t i = 2; i < result.size(); i++) {
            result[i] = ((result[i - 2] * get_2(i - 1)) % 1000000007 + (result[i - 1] * get_1(i)) % 1000000007) % 1000000007;
        }
        return *(--result.end());
    }
};