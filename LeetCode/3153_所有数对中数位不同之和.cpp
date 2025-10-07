// 3153_所有数对中数位不同之和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<vector<long long>> count;
        while (nums[0] > 0) {
            count.emplace_back(10, 0);
            count.back()[nums[0] % 10]++;
            nums[0] /= 10;
        }
        for (size_t i = 1; i < nums.size(); i++) {
            for (size_t j = 0; j < count.size(); j++) {
                count[j][nums[i] % 10]++;
                nums[i] /= 10;
            }
        }
        for (size_t j = 0; j < count.size(); j++) {
            cout << "----- " << j << " -----" << endl;
            for (size_t digit = 0; digit < 10; digit++) {
                cout << digit << ": " << count[j][digit] << endl;
            }
        }
        long long sum = 0;
        for (size_t j = 0; j < count.size(); j++) {
            for (size_t digit1 = 0; digit1 + 1 < 10; digit1++) {
                for (size_t digit2 = digit1 + 1; digit2 < 10; digit2++) {
                    sum += count[j][digit1] * count[j][digit2];
                }
            }
        }
        return sum;
    }
};
