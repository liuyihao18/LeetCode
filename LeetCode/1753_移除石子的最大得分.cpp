// 1753_移除石子的最大得分.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int stones[] = {a, b, c};
        sort(begin(stones), end(stones));
        int result = 0;
        a = stones[0], b = stones[1], c = stones[2];
        if (a < c - b) {
            result += a;
            c -= a;
        }
        else {
            result += c - b;
            a -= (c - b);
            c = b;
            result += a;
            c -= a / 2;
            b -= a - a / 2;
            a -= a;
        }
        result += b;
        return result;
    }
};
