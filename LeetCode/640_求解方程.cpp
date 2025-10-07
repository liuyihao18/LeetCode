// 640_求解方程.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string solveEquation(string equation) {
        equation += "#";
        int left = 0, right = 0;
        int positive = 1;
        int num = 0;
        int dir = 1;
        bool singleX = true;
        bool isX = false;
        for (auto c : equation) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
                singleX = false;
            }
            else if (c == 'x') {
                isX = true;
            }
            else if (c == '+' || c == '-' || c == '=' || c == '#') {
                if (isX) {
                    if (singleX) {
                        num = 1;
                    }
                    left += num * positive * dir;
                }
                else {
                    right -= num * positive * dir;
                }
                num = 0;
                positive = c == '-' ? -1 : 1;
                singleX = true;
                isX = false;
            }
            if (c == '=') {
                dir = -1;
            }
        }
        if (left == 0) {
            if (right == 0) {
                return "Infinite solutions"s;
            }
            else {
                return "No solution"s;
            }
        }
        else {
            return "x="s + to_string(right / left);
        }
    }
};
