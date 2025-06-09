// 2530_执行K次操作后的最大分数.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (k-- > 0) {
            int num = pq.top();
            pq.pop();
            score += num;
            pq.push(static_cast<int>(ceil(num / 3.0)));
        }
        return score;
    }
};
