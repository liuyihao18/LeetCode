// 495_ÌáÄª¹¥»÷.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        int begin_time = -1;
        int end_time = -1;
        for (auto time : timeSeries) {
            if (time > end_time) {
                result += end_time - begin_time;
                begin_time = time;
                end_time = time + duration;
            }
            else {
                end_time = time + duration;
            }
        }
        result += end_time - begin_time;
        return result;
    }
};
