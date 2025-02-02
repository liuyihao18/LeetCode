// 598_区间加法_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minM = m, minN = n;
        for_each(ops.begin(), ops.end(), 
            [&](const vector<int>& op) {
                minM = min(minM, op[0]);
                minN = min(minN, op[1]);
            }
        );
        return minM * minN;
    }
};
