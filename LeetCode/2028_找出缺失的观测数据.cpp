// 2028_找出缺失的观测数据.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = static_cast<int>(rolls.size());
        int total = mean * (m + n);
        for (auto roll : rolls) {
            total -= roll;
        }
        if (total < n || total > 6 * n) {
            return {};
        }
        vector<int> result;
        int i = 0;
        while (i < n && total > (n - i)) {
            int temp = min(6, total - (n - i - 1));
            result.push_back(temp);
            total -= temp;
            i++;
        }
        while (i < n) {
            result.push_back(1);
            total--;
            i++;
        }
        return result;
    }
};
