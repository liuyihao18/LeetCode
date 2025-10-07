// 915_·Ö¸îÊý×é.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> maximum(nums.size(), INT_MIN);
        vector<int> minimum(nums.size(), INT_MAX);
        stack<int> st;
        for (size_t i = 0; i < nums.size(); i++) {
            while (!st.empty() && st.top() < nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                st.push(nums[i]);
            }
            maximum[i] = st.top();
        }
        while (!st.empty()) {
            st.pop();
        }
        for (size_t i = 0; i < nums.size(); i++) {
            while (!st.empty() && st.top() > nums[nums.size() - i - 1]) {
                st.pop();
            }
            if (st.empty()) {
                st.push(nums[nums.size() - i - 1]);
            }
            minimum[nums.size() - i - 1] = st.top();
        }
        for (size_t l = 0; l + 1 < nums.size(); l++) {
            if (maximum[l] <= minimum[l + 1]) {
                return static_cast<int>(l + 1);
            }
        }
        return -1;
    }
};
