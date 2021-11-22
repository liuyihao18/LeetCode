// 384_´òÂÒÊı×é.cpp
#include "custom.h"
ustd

class Solution {
    vector<int> _nums;
    vector<int> nums;
public:
    Solution(vector<int>& nums) : _nums(nums), nums(nums) {}

    vector<int> reset() {
        return nums = _nums;
    }

    vector<int> shuffle() {
        // random_shuffle(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            swap(nums[i], nums[i - rand() % (i + 1)]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
