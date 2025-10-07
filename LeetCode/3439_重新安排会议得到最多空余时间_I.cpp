// 3439_重新安排会议得到最多空余时间_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
		int n = static_cast<int>(startTime.size());
        
        int totalTime = 0;
        for (int i = 0; i < k; i++) {
            totalTime += endTime[i] - startTime[i];
        }

        int freeTime = 0;
        if (k == n) {
            freeTime = eventTime - totalTime;
        }

        // 单边固定
        for (int i = 0; i + k < n; i++) {
            totalTime += endTime[i + k] - startTime[i + k];

			int left1 = i == 0 ? 0 : endTime[i - 1];
            int left2 = startTime[i];
            int right1 = endTime[i + k];
			int right2 = i + k + 1 == n ? eventTime : startTime[i + k + 1];
            freeTime = max(freeTime, right1 - left1 - totalTime);
            freeTime = max(freeTime, right2 - left2 - totalTime);
            
            totalTime -= endTime[i] - startTime[i];
        }

        return freeTime;
    }
};
