// 1706_Çò»áÂäºÎ´¦.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        vector<int> position(n, 0);
        iota(position.begin(), position.end(), 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (position[j] != -1) {
                    if (grid[i][position[j]] == 1) {
                        position[j] = position[j] + 1 == n || grid[i][static_cast<size_t>(position[j] + 1)] == -1 ? -1 : position[j] + 1;
                    }
                    else {
                        position[j] = position[j] == 0 || grid[i][static_cast<size_t>(position[j] - 1)] == 1 ? -1 : position[j] - 1;
                    }
                }
            }
        }
        return position;
    }
};

/*
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid.front().size();
        vector<int> result(n, 0);
        for (size_t j = 0; j < n; j++) {
            result[j] = static_cast<int>(j);
        }
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                int curr = result[j];
                if (curr == -1) {
                    continue;
                }
                if (grid[i][curr] == 1) {
                    if (curr == n - 1 || grid[i][static_cast<size_t>(curr) + 1] == -1) {
                        result[j] = -1;
                    }
                    else {
                        result[j] = curr + 1;
                    }
                }
                else {
                    if (curr == 0 || grid[i][static_cast<size_t>(curr) - 1] == 1) {
                        result[j] = -1;
                    }
                    else {
                        result[j] = curr - 1;
                    }
                }
            }
        }
        return result;
    }
};
*/
