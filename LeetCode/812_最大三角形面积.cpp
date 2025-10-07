// 812_最大三角形面积.cpp
#include "stdafx.h"
ustd

#define x(p) p[0]
#define y(p) p[1]

class Solution {
    double getArea(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        return 0.5 * abs(x(p1) * y(p2) + x(p2) * y(p3) + x(p3) * y(p1) - x(p1) * y(p3) - x(p2) * y(p1) - x(p3) * y(p2));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                for (size_t k = j + 1; k < points.size(); k++) {
                    area = max(area, getArea(points[i], points[j], points[k]));
                }
            }
        }
        return area;
    }
};
