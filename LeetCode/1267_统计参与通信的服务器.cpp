// 1267_ͳ�Ʋ���ͨ�ŵķ�����.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid.front().size();
        vector<int> row(m, 0), col(n, 0);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int result = 0;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] && (row[i] > 1 || col[j] > 1)) {
                    result++;
                }
            }
        }
        return result;
    }
};
