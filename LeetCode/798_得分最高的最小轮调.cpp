// 798_得分最高的最小轮调.cpp
#include "stdafx.h"
ustd

// TODO: 差分数组（https://leetcode-cn.com/problems/smallest-rotation-with-highest-score/solution/de-fen-zui-gao-de-zui-xiao-lun-diao-by-l-hbtd/）
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> diffs(n);
        for (size_t i = 0; i < n; i++) {
            size_t low = (i + 1) % n;
            size_t high = (i - nums[i] + n + 1) % n;
            diffs[low]++;
            diffs[high]--;
            if (low >= high) {
                diffs[0]++;
            }
        }
        size_t bestIndex = 0;
        int maxScore = 0;
        int score = 0;
        for (size_t i = 0; i < n; i++) {
            score += diffs[i];
            if (score > maxScore) {
                bestIndex = i;
                maxScore = score;
            }
        }
        return static_cast<int>(bestIndex);
    }
};
