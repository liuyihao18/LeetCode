// 3487_ɾ��������������Ԫ�غ�.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> us;
        int maximum = INT_MIN;
        for (int num : nums) {
            if (num > 0) {
                us.insert(num);
            }
            maximum = max(maximum, num);
        }
        if (us.empty()) {
            return maximum;
        }
        else {
            return accumulate(us.begin(), us.end(), 0);
        }
    }
};
