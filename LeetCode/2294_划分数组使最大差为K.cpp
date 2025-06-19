// 2294_划分数组使最大差为K.cpp
#include "custom.h"
ustd

/**
* Method 1
*/
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        int result = 0;
        int left = INT_MIN / 2;
        for (size_t i = 0; i < n; i++) {
            if (nums[i] - left > k) {
                result++;
                left = nums[i];
            }
        }
        return result;
    }
};
    
/**
* Method 2
*/

/*
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        int result = 0;
        auto iter = nums.begin();
        while (iter != nums.end()) {
            iter = upper_bound(iter, nums.end(), *iter + k);
            result++;
        }
        return result;
    }
};
*/
