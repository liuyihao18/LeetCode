// 3335_字符串转换后的长度_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = static_cast<int>(1e9 + 7);
        vector<int> counts(26, 0);
        for (auto c : s) {
            counts[static_cast<size_t>(c - 'a')]++;
        }
        for (int i = 0; i < t; i++) {
            int z = counts[25];
            for (size_t j = 25; j > 0; j--) {
                counts[j] = counts[j - 1];
            }
            counts[0] = z;
            counts[1] = (counts[1] + z) % MOD;
        }
        int result = 0;
        for (auto count : counts) {
            result = (result + count) % MOD;
        }
        return result;
    }
};
