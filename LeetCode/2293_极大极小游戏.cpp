// 2293_极大极小游戏.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> newNums(nums.size() / 2);
            for (size_t i = 0; i < newNums.size(); i++) {
                if (i & 1) {
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
                else {
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
            }
            nums = std::move(newNums);
        }
        return nums[0];
    }
};
