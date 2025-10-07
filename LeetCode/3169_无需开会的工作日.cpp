// 3169_无需开会的工作日.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
		size_t n = meetings.size();
        ranges::sort(meetings, 
            [](const vector<int>& meeting1, const vector<int>& meeting2) {
			    return meeting1[0] < meeting2[0];
            }
        );
        int res = meetings[0][0] - 1;
		int right = meetings[0][1];
        for (size_t i = 1; i < n; i++) {
            if (meetings[i][0] - right - 1 > 0) {
                res += meetings[i][0] - right - 1;
            }
			right = max(right, meetings[i][1]);
        }
		res += days - right;
        return res;
    }
};
