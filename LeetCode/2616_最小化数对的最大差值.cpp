// 2616_最小化数对的最大差值.cpp
#include "stdafx.h"
ustd

class Solution {
    bool check(const map<int, int>& counts, int p, int diff) {
        auto iter = counts.begin();
        int borrow = 0;
        while (p > 0 && iter != counts.end()) {
            p -= (iter->second - borrow) / 2;
            auto next_iter = next(iter);
            if ((iter->second - borrow) & 1 && next_iter != counts.end() && next_iter->first - iter->first <= diff) {
                p -= 1;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            iter = next_iter;
        }
        return p <= 0;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int left = 0, right = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        while (left < right) { // [left, right]
            int mid = (left + right) / 2;
            if (check(counts, p, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
