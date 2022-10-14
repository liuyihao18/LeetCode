// 940_不同的子序列_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> vec(26);
        for (char c : s)
            vec[static_cast<size_t>(c) - 'a'] = accumulate(vec.begin(), vec.end(), 1LL) % 1000000007;
        return accumulate(vec.begin(), vec.end(), 0LL) % 1000000007;
    }
};
