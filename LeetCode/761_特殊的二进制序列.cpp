// 761_特殊的二进制序列.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) {
            return s;
        }
        size_t cnt = 0, left = 0, n = s.size();
        vector<string> subs;
        for (size_t i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
            }
            else {
                cnt--;
                if (cnt == 0) {
                    subs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                    left = i + 1;
                }
            }
        }
        sort(subs.begin(), subs.end(), greater<string>());
        string ans = accumulate(subs.begin(), subs.end(), ""s);
        return ans;
    }
};
