// 3633_最早完成陆地和水上游乐设施的时间_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        const size_t n1 = landStartTime.size();
        const size_t n2 = waterStartTime.size();
        int ans = INT_MAX;
        for (size_t i = 0; i < n1; i++)
        {
            const int time1 = landStartTime[i] + landDuration[i];
            for (size_t j = 0; j < n2; j++)
            {
                ans = min(ans, max(time1, waterStartTime[j]) + waterDuration[j]);
            }
        }
        for (size_t j = 0; j < n2; j++)
        {
            const int time2 = waterStartTime[j] + waterDuration[j];
            for (size_t i = 0; i < n1; i++)
            {
                ans = min(ans, max(time2, landStartTime[i]) + landDuration[i]);
            }
        }
        return ans;
    }
};
