// 2208_将数组和减半的最少操作次数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        priority_queue<double> q(nums.begin(), nums.end());
        double curr = sum;
        double cnt = 0;
        while (curr * 2 > sum) {
            double top = q.top();
            q.pop();
            curr -= top;
            top /= 2;
            curr += top;
            q.push(top);
            cnt++;
        }
        return static_cast<int>(cnt);
    }
};
