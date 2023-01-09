// 1806_还原排列的最少操作步数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> initial(n, 0);
        iota(initial.begin(), initial.end(), 0);
        vector<int> perm(initial);
        int result = 0;
        do {
            vector<int> temp(perm);
            for (size_t i = 0; i < static_cast<size_t>(n); i++) {
                if (i & 1) {
                    temp[i] = perm[n / 2 + (i - 1) / 2];
                }
                else {
                    temp[i] = perm[i / 2];
                }
            }
            perm = std::move(temp);
            result++;
        } while (perm != initial);
        return result;
    }
};
