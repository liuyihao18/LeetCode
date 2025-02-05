// 90_×Ó¼¯_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        set<vector<int>> results;
        for (size_t i = 0; i < (1ULL << n); i++) {
            vector<int> subset;
            for (size_t j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subset.push_back(nums[j]);
                }
            }
            results.insert(subset);
        }
        return vector<vector<int>>(results.begin(), results.end());
    }
};
