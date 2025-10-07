// 223_矩形面积.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool in_area(int x, int y, int _x1, int _y1, int _x2, int _y2) {
        return x >= _x1 && x <= _x2 && y >= _y1 && y <= _y2;
    }
    int cross_area(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2, bool& match) {
        if (ay2 > by2 && ay1 < by1 && bx2 > ax2 && bx1 < ax1) {
            match = true;
            return (by2 - by1) * (ax2 - ax1);
        }
        return 0;
    }
    int four_in_area(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2, bool& match) {
        if (in_area(ax1, ay1, bx1, by1, bx2, by2) &&
            in_area(ax2, ay2, bx1, by1, bx2, by2)) {
            match = true;
            return (ay2 - ay1) * (ax2 - ax1);
        }
        return 0;
    }
    int two_in_area(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2, bool& match) {
        if (in_area(ax1, ay1, bx1, by1, bx2, by2) &&
            in_area(ax1, ay2, bx1, by1, bx2, by2)) {
            match = true;
            return (bx2 - ax1) * (ay2 - ay1);
        }
        if (in_area(ax2, ay1, bx1, by1, bx2, by2) &&
            in_area(ax2, ay2, bx1, by1, bx2, by2)) {
            match = true;
            return (ax2 - bx1) * (ay2 - ay1);
        }
        if (in_area(ax1, ay1, bx1, by1, bx2, by2) &&
            in_area(ax2, ay1, bx1, by1, bx2, by2)) {
            match = true;
            return (by2 - ay1) * (ax2 - ax1);
        }
        if (in_area(ax1, ay2, bx1, by1, bx2, by2) &&
            in_area(ax2, ay2, bx1, by1, bx2, by2)) {
            match = true;
            return (ay2 - by1) * (ax2 - ax1);
        }
        return 0;
    }
    int one_in_area(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2, bool& match) {
        if (in_area(ax1, ay1, bx1, by1, bx2, by2)) {
            match = true;
            return (by2 - ay1) * (bx2 - ax1);
        }
        if (in_area(ax1, ay2, bx1, by1, bx2, by2)) {
            match = true;
            return (ay2 - by1) * (bx2 - ax1);
        }
        if (in_area(ax2, ay1, bx1, by1, bx2, by2)) {
            match = true;
            return (by2 - ay1) * (ax2 - bx1);
        }
        if (in_area(ax2, ay2, bx1, by1, bx2, by2)) {
            match = true;
            return (ay2 - by1) * (ax2 - bx1);
        }
        return 0;
    }
    int enumulate(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a_area = (ay2 - ay1) * (ax2 - ax1);
        int b_area = (by2 - by1) * (bx2 - bx1);
        int both_area = 0;
        bool match = false;
        if (!match) {
            both_area = cross_area(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, match);
        }
        if (!match) {
            both_area = cross_area(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2, match);
        }
        if (!match) {
            both_area = four_in_area(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, match);
        }
        if (!match) {
            both_area = four_in_area(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2, match);
        }
        if (!match) {
            both_area = two_in_area(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, match);
        }
        if (!match) {
            both_area = two_in_area(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2, match);
        }
        if (!match) {
            both_area = one_in_area(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, match);
        }
        return a_area + b_area - both_area;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a_area = (ay2 - ay1) * (ax2 - ax1);
        int b_area = (by2 - by1) * (bx2 - bx1);
        int both_x = min(ax2, bx2) - max(ax1, bx1); // 重叠部分在x轴的投影
        int both_y = min(ay2, by2) - max(ay1, by1); // 重叠部分在y轴的投影
        int both_area = max(both_x, 0) * max(both_y, 0);
        return a_area + b_area - both_area;
    }
};