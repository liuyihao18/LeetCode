// 1222_可以攻击国王的皇后.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> chess(8, vector<bool>(8, false));
        for (const auto& queen : queens) {
            chess[queen.front()][queen.back()] = true;
        }
        vector<vector<int>> result;
        // 左
        int x = king.front(), y = king.back();
        for (int lx = x - 1; lx >= 0; lx--) {
            if (chess[lx][y]) {
                result.push_back({ lx, y });
                break;
            }
        }
        // 右
        for (int rx = x + 1; rx < 8; rx++) {
            if (chess[rx][y]) {
                result.push_back({ rx, y });
                break;
            }
        }
        // 上
        for (int uy = y + 1; uy < 8; uy++) {
            if (chess[x][uy]) {
                result.push_back({ x, uy });
                break;
            }
        }
        // 下
        for (int dy = y - 1; dy >= 0; dy--) {
            if (chess[x][dy]) {
                result.push_back({ x, dy });
                break;
            }
        }
        // 左上
        for (int i = 1; x - i >= 0 && y + i < 8; i++) {
            if (chess[x - i][y + i]) {
                result.push_back({ x - i,y + i });
                break;
            }
        }
        // 右上
        for (int i = 1; x + i < 8 && y + i < 8; i++) {
            if (chess[x + i][y + i]) {
                result.push_back({ x + i,y + i });
                break;
            }
        }
        // 左下
        for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
            if (chess[x - i][y - i]) {
                result.push_back({ x - i,y - i });
                break;
            }
        }
        // 右下
        for (int i = 1; x + i < 8 && y - i >= 0; i++) {
            if (chess[x + i][y - i]) {
                result.push_back({ x + i, y - i });
                break;
            }
        }
        return result;
    }
};
