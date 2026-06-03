// 3635_最早完成陆地和水上游乐设施的时间_II.cpp
#include "stdafx.h"
ustd

class Solution {
    int solve(vector<int>& startTime1, vector<int>& duration1,
              vector<int>& startTime2, vector<int>& duration2)
    {
        int finish1 = INT_MAX;
        for (size_t i = 0, n = startTime1.size(); i < n; i++)
        {
            finish1 = min(finish1, startTime1[i] + duration1[i]);
        }
        int finish2 = INT_MAX;
        for (size_t i = 0, n = startTime2.size(); i < n; i++)
        {
            finish2 = min(finish2, max(finish1, startTime2[i]) + duration2[i]);
        }
        return finish2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }
};
