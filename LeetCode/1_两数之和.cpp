// 1_两数之和.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            if (um.count(target - nums[i])) {
                return { i, um[target - nums[i]] };
            }
            um[nums[i]] = i;
        }
        return { -1, -1 };
    }
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx(nums.size(), 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return nums[i] < nums[j]; });
        sort(nums.begin(), nums.end());
        vector<int> result;
        for (auto iter1 = nums.begin(); iter1 != nums.end(); ++iter1) {
            auto iter2 = lower_bound(nums.begin(), nums.end(), target - *iter1);
            if (iter2 != iter1 && iter2 != nums.end() && *iter1 + *iter2 == target) {
                result = { idx[distance(nums.begin(), iter1)],
                    idx[distance(nums.begin(), iter2)]
                };
                break;
            }
        }
        return result;
    }
};
*/
