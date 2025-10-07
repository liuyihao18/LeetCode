// 1037_有效的回旋镖.cpp
#include "stdafx.h"
ustd

/*
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        const vector<int>& p1 = points[0];
        const vector<int>& p2 = points[1];
        const vector<int>& p3 = points[2];
        if (p1 == p2 || p1 == p3 || p2 == p3) {
            return false;
        }
        if (p1[0] == p2[0] && p2[0] == p3[0]) {
            return false;
        }
        else if (p1[0] == p2[0] || p2[0] == p3[0]) {
            return true;
        }
        else {
            double k1 = (p2[1] - p1[1]) * 1.0 / (p2[0] - p1[0]);
            double k2 = (p3[1] - p2[1]) * 1.0 / (p3[0] - p2[0]);
            return k1 != k2;
        }
    }
};
*/

// 三点共线转化为三角形面积为0，使用行列式计算
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0];
        int x2 = points[1][0];
        int x3 = points[2][0];
        int y1 = points[0][1];
        int y2 = points[1][1];
        int y3 = points[2][1];
        return (x1 * y2 + x3 * y1 + x2 * y3) - (x1 * y3 + x2 * y1 + x3 * y2);
    }
};