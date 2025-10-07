// 741_ժӣ��.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        vector<vector<int>> f(n, vector<int>(n, INT_MIN));
        f[0][0] = grid[0][0];
        size_t const1 = 1;
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = min(k, n - 1); x1 >= max(k - n + 1, 0); --x1) {
                for (int x2 = min(k, n - 1); x2 >= x1; --x2) {
                    int y1 = k - x1, y2 = k - x2;
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        f[x1][x2] = INT_MIN;
                        continue;
                    }
                    int res = f[x1][x2]; // ������
                    if (x1) {
                        res = max(res, f[x1 - const1][x2]); // ���£�����
                    }
                    if (x2) {
                        res = max(res, f[x1][x2 - const1]); // ���ң�����
                    }
                    if (x1 && x2) {
                        res = max(res, f[x1 - const1][x2 - const1]); // ������
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { // �����ظ�ժͬһ��ӣ��
                        res += grid[x2][y2];
                    }
                    f[x1][x2] = res;
                }
            }
        }
        return max(f.back().back(), 0);
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/cherry-pickup/solution/zhai-ying-tao-by-leetcode-solution-1h3k/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
