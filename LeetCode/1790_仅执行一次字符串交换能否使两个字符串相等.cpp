// 1790_仅执行一次字符串交换能否使两个字符串相等.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int cnt = 0;
        size_t j = 0, k = 0;
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                ++cnt;
                if (cnt == 1) {
                    j = i;
                }
                else if (cnt == 2) {
                    k = i;
                }
                else {
                    return false;
                }
            }
        }
        return cnt == 0 || (cnt == 2 && s1[j] == s2[k] && s1[k] == s2[j]);
    }
};