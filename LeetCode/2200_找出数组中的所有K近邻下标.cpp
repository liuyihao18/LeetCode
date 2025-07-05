// 2200_找出数组中的所有K近邻下标.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = static_cast<int>(nums.size());
        vector<int> results;
        int curr = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                for (int j = max(curr - i + 1, -k); j <= min(n - i - 1, k); j++) {
                    // i + j = i + curr - i + 1 = curr + 1;
                    // i + j = i + n - i - 1 = n - 1;
                    if (i + j > curr) {
                        curr = i + j;
                        results.push_back(curr);
                    }
                }
            }
        }
        return results;
    }
};
