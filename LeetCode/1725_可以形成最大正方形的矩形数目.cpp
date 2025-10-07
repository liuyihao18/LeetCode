// 1725_可以形成最大正方形的矩形数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        pair<int, int> max_square = { 0,0 };
        for (const auto& rectangle : rectangles) {
            int square_len = min(rectangle.front(), rectangle.back());
            if (square_len > max_square.first) {
                max_square = { square_len, 1 };
            }
            else if (square_len == max_square.first) {
                max_square.second++;
            }
        }
        return max_square.second;
    }
};
