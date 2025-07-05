// 3085_成为K特殊字符串需要删除的最少字符数.cpp
#include "custom.h"
ustd

class Solution {
    int deleteForTarget(const vector<int>& counts, int k, int target) {
        int result = 0;
        for (int count : counts) {
            if (count < target) {
                result += count;
            }
            else if (target + k < count) {
                result += count - target - k;
            }
        }
        return result;
    }
public:
    int minimumDeletions(string word, int k) {
        vector<int> counts(26, 0);
        for (char c : word) {
            counts[static_cast<size_t>(c - 'a')]++;
        }
        int result = INT_MAX;
        for (int count : counts) {
            result = min(result, deleteForTarget(counts, k, count));
        }
        return result;
    }
};
