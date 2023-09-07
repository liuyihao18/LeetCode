// 2594_修车的最少时间.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0;
        long long right = 1LL * *max_element(ranks.begin(), ranks.end()) * cars * cars;
        while (left < right) {
            long long mid = (left + right) >> 1;
            int doneCars = 0;
            for (auto rank : ranks) {
                doneCars += sqrt(mid / rank);
            }
            if (doneCars < cars) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
