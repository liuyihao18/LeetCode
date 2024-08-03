// 3143_正方形中的最多点数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // 小于次小半径的点都是合法的点
        vector<int> min1(26, 1000000001);
        int min2 = 1000000001;
        for (size_t i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1], c = s[i] - 'a';
            // 某个标签的点的半径
            int d = max(abs(x), abs(y));
            // 统计某个标签的点的最小半径和所有标签点的次小半径
            if (d < min1[c]) {
                min2 = min(min2, min1[c]);
                min1[c] = d;
            }
            else if (d < min2) {
                min2 = d;
            }
        }
        int res = 0;
        for (auto m : min1) {
            if (m < min2) {
                ++res;
            }
        }
        return res;
    }
};
