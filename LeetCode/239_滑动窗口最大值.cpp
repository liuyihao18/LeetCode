// 239_滑动窗口最大值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, size_t k) {
        deque<int> q;
        for (size_t i = 0; i < k; i++) {
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        vector<int> result;
        result.push_back(q.front());
        for (size_t i = k; i < nums.size(); i++) {
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }
            q.push_back(nums[i]);
            if (q.front() == nums[i - k]) {
                q.pop_front();
            }
            result.push_back(q.front());
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, size_t k) {
        map<int, int, greater<>> slidingWindow;
        for (size_t i = 0; i < k; i++) {
            ++slidingWindow[nums[i]];
        }
        vector<int> result;
        result.push_back(slidingWindow.begin()->first);
        for (size_t i = k; i < nums.size(); i++) {
            ++slidingWindow[nums[i]];
            if (--slidingWindow[nums[i - k]] == 0) {
                slidingWindow.erase(nums[i - k]);
            }
            result.push_back(slidingWindow.begin()->first);
        }
        return result;
    }
};
*/
