// 1222_���Թ��������Ļʺ�.cpp
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
        // ��
        int x = king.front(), y = king.back();
        for (int lx = x - 1; lx >= 0; lx--) {
            if (chess[lx][y]) {
                result.push_back({ lx, y });
                break;
            }
        }
        // ��
        for (int rx = x + 1; rx < 8; rx++) {
            if (chess[rx][y]) {
                result.push_back({ rx, y });
                break;
            }
        }
        // ��
        for (int uy = y + 1; uy < 8; uy++) {
            if (chess[x][uy]) {
                result.push_back({ x, uy });
                break;
            }
        }
        // ��
        for (int dy = y - 1; dy >= 0; dy--) {
            if (chess[x][dy]) {
                result.push_back({ x, dy });
                break;
            }
        }
        // ����
        for (int i = 1; x - i >= 0 && y + i < 8; i++) {
            if (chess[x - i][y + i]) {
                result.push_back({ x - i,y + i });
                break;
            }
        }
        // ����
        for (int i = 1; x + i < 8 && y + i < 8; i++) {
            if (chess[x + i][y + i]) {
                result.push_back({ x + i,y + i });
                break;
            }
        }
        // ����
        for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
            if (chess[x - i][y - i]) {
                result.push_back({ x - i,y - i });
                break;
            }
        }
        // ����
        for (int i = 1; x + i < 8 && y - i >= 0; i++) {
            if (chess[x + i][y - i]) {
                result.push_back({ x + i, y - i });
                break;
            }
        }
        return result;
    }
};
