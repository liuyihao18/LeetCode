// 539_最小时间差.cpp
#include "custom.h"
ustd

class Solution {
    int s2i(char c) {
        return c - '0';
    }
    int tom(const string& time_str) {
        int hours = 10 * s2i(time_str[0]) + s2i(time_str[1]);
        int minutes = 10 * s2i(time_str[3]) + s2i(time_str[4]);
        return hours * 60 + minutes;
    }
public:
#ifdef STRING_SORT
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end(), [this](const string& s1, const string& s2) {
            return tom(s1) < tom(s2);
            });
        int res = INT_MAX;
        for (size_t i = 0; i + 1 < timePoints.size(); i++) {
            res = min(res, tom(timePoints[i + 1]) - tom(timePoints[i]));
        }
        res = min(res, tom(timePoints.front()) + 24 * 60 - tom(timePoints.back()));
        return res;
    }
#else
    int findMinDifference(vector<string>& timePoints) {
        // 鸽巢原理
        if (timePoints.size() > 24 * 60) {
            return 0;
        }
        vector<int> timePointsMinutes;
        transform(timePoints.begin(), timePoints.end(), back_inserter(timePointsMinutes),
            [this](const string& s) {
                return tom(s);
            });
        sort(timePointsMinutes.begin(), timePointsMinutes.end());
        int res = INT_MAX;
        for (size_t i = 0; i + 1 < timePointsMinutes.size(); i++) {
            res = min(res, timePointsMinutes[i + 1] - timePointsMinutes[i]);
        }
        res = min(res, timePointsMinutes.front() + 24 * 60 - timePointsMinutes.back());
        return res;
    }
#endif // STRING_SORT
};
