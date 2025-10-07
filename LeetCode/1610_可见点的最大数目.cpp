// 1610_可见点的最大数目.cpp
#include "stdafx.h"
ustd

class Solution {
    const double PI = 3.14159265;
    double diff(double begin, double end) {
        double res = end - begin + 360;
        while (res >= 360) {
            res -= 360;
        }
        while (res < 0) {
            res += 360;
        }
        return res;
    }
public:
    int visiblePoints(const vector<vector<int>>& points, int angle, const vector<int>& location) {
        size_t cover = 0;
        vector<double> angles;
        for (auto iter = points.begin(); iter != points.end(); ++iter) {
            if (*iter == location) {
                cover += 1;
            }
            else {
                angles.push_back(atan2(iter->back() - location.back(), iter->front() - location.front()) / PI * 180.0);
            }
        }
        sort(angles.begin(), angles.end());
        size_t window_begin = 0;
        size_t window_end = 0;
        size_t total_length = angles.size();
        size_t max_length = 0;
        while (total_length) {
            size_t next = (window_end + 1) % total_length;
            if (diff(angles[window_begin], angles[next]) <= angle) {
                window_end = next;
                max_length = max(max_length, (window_end - window_begin + total_length) % total_length + 1);
                if (max_length == total_length) {
                    break;
                }
            }
            else {
                if ((window_begin = (window_begin + 1) % total_length) == 0) {
                    break;
                }
            }
        }
        return static_cast<int>(max_length + cover);
    }
};
