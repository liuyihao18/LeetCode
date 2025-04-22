// 3152_ÌØÊâÊý×é_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, int>> specialArrayRange;
        int left = 0;
        for (size_t i = 0; i + 1 < nums.size(); i++) {
            if (~(nums[i] + nums[i + 1]) & 1) {
                specialArrayRange.emplace_back(left, i + 1);
                left = static_cast<int>(i) + 1;
            }
        }
        if (left != nums.size()) {
            specialArrayRange.emplace_back(left, nums.size());
        }
        for (auto& [l, r] : specialArrayRange) {
            cout << "Range: [" << l << ", " << r << ")" << endl;
        }
        vector<bool> results;
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];
            auto iter = --upper_bound(specialArrayRange.begin(), specialArrayRange.end(), from, 
                [](int from, const auto& range) {
                    return from < range.first;
                }
            );
            if (iter != specialArrayRange.end()) {
                cout << "Search: [" << iter->first << ", " << iter->second << ")" << endl;
            }
            results.push_back(iter != specialArrayRange.end() && to < iter->second);
        }
        return results;
    }
};
