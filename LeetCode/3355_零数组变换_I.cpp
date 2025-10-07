// 3355_ÁãÊý×é±ä»»_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        size_t n = nums.size();
        vector<int> diff(n);
        for (const vector<int>& query : queries) {
            int l = query[0];
            int r = query[1];
            diff[r]++;
            if (l - 1 >= 0) {
                diff[static_cast<size_t>(l - 1)]--;
            }
        }
        bool flag = true;
        int sum = 0;
        for (size_t i = n - 1; i != -1; i--) {
            sum += diff[i];
            if (sum < nums[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
