// 907_子数组的最小值之和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        vector<int> st;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.back()] >= arr[i]) {
                st.pop_back();
            }
            left[i] = i - (st.empty() ? -1 : st.back());
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.back()] > arr[i]) {
                st.pop_back();
            }
            right[i] = (st.empty() ? n : st.back()) - i;
            st.push_back(i);
        }
        long long result = 0;
        long long mod = static_cast<long long>(1e9) + 7;
        for (int i = 0; i < n; i++) {
            result = (result + static_cast<long long>(right[i]) * left[i] * arr[i]) % mod;
        }
        return static_cast<int>(result);
    }
};
