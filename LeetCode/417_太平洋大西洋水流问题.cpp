// 417_太平洋大西洋水流问题.cpp
#include "custom.h"
ustd

#define INT(x) static_cast<int>(x)
#define SIZE(x) static_cast<size_t>(x)

class Solution {
    void check(const vector<vector<int>>& heights, vector<vector<bool>>& pacific, size_t i, size_t j) {
        size_t m = heights.size();
        size_t n = heights.front().size();
        queue<pair<size_t, size_t>> q;
        q.push({ i,j });
        while (!q.empty()) {
            pair<size_t, size_t> curr = q.front();
            q.pop();
            size_t i = curr.first, j = curr.second;
            if (!pacific[i][j]) {
                pacific[i][j] = true;
                if (i > 0 && heights[i][j] <= heights[i - 1][j]) q.push({ i - 1,j });
                if (j > 0 && heights[i][j] <= heights[i][j - 1]) q.push({ i, j - 1 });
                if (i + 1 < m && heights[i][j] <= heights[i + 1][j]) q.push({ i + 1,j });
                if (j + 1 < n && heights[i][j] <= heights[i][j + 1]) q.push({ i, j + 1 });
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        size_t m = heights.size();
        size_t n = heights.front().size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (size_t i = 0; i < m; i++) {
            check(heights, pacific, i, 0);
            check(heights, atlantic, i, n - 1);
        }
        for (size_t j = 0; j < n; j++) {
            check(heights, pacific, 0, j);
            check(heights, atlantic, m - 1, j);
        }
        vector<vector<int>> result;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({ INT(i), INT(j) });
                }
            }
        }
        return result;
    }
};
