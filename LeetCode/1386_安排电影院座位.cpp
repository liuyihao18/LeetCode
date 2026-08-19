// 1386_安排电影院座位.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxNumberOfFamilies(const int n, const vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> um;
        for (auto&& reservedSeat : reservedSeats)
        {
            const int row = reservedSeat[0] - 1;
            const int col = reservedSeat[1] - 1;
            um[row] = um[row] | 1 << col;
        }
        int result = 2 * n;
        for (auto&& val : um | views::values)
        {
	        if ((val & 0x1E) == 0 && (val & 0x1E0) == 0)
	        {
                continue;
	        }
            if ((val & 0x1E) == 0 || (val & 0x78) == 0 || (val & 0x1E0) == 0)
            {
                result--;
                continue;
            }
        	result -= 2;
        }
        return result;
    }
};
