// 1559_二维网格图中探测环.cpp
#include "stdafx.h"
ustd

class Solution {
    struct State
    {
        int x;
        int y;
        int lastX;
        int lastY;
    };

    bool dfs(const vector<vector<char>>& grid, const int originX, const int originY, vector<vector<bool>>& visited)
    {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid.front().size());
        stack<State> st;
        st.emplace(originX, originY, -1, -1);
        while (!st.empty())
        {
            const auto [x, y, lastX, lastY] = st.top();
            st.pop();
            if (visited[x][y]) return true;
            visited[x][y] = true;
            for (constexpr int directions[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; 
                 auto&& direction : directions)
            {
                const int newX = x + direction[0];
                const int newY = y + direction[1];
                const bool within = newX >= 0 && newX < m && newY >= 0 && newY < n;
                const bool notComeBack = newX != lastX || newY != lastY;
                if (within && notComeBack && grid[newX][newY] == grid[x][y])
                {
                    st.emplace(newX, newY, x, y);
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(const vector<vector<char>>& grid) {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid.front().size());
        vector visited(m, vector(n, false));
        for (int i = 0; i < m; i++)
        {
	        for (int j = 0; j < n; j++)
	        {
		        if (!visited[i][j] && dfs(grid, i, j, visited))
		        {
                    return true;
		        }
	        }
        }
        return false;
    }
};
