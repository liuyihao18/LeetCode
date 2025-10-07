// 1200_×îÐ¡¾ø¶Ô²î.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (size_t i = 0; i + 1 < arr.size(); i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> result;
        for (size_t i = 0; i + 1 < arr.size(); i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                result.push_back({ arr[i], arr[i + 1] });
            }
        }
        return result;
    }
};
