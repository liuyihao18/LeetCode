// 1812_判断国际象棋棋盘中一个格子的颜色.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a') + (coordinates[1] - '1')) & 1;
    }
};
