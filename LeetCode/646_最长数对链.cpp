// 646_最长数对链.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[1] < p2[1];
            });
        int right = INT_MIN;
        int result = 0;
        for (const vector<int>& pair : pairs) {
            if (pair[0] > right) {
                result++;
                right = pair[1];
            }
        }
        return result;
    }
};
