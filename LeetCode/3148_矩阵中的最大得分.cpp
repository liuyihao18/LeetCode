// 3148_矩阵中的最大得分.cpp
#include "custom.h"
ustd

// 反向索引必TLE
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        using Position = pair<size_t, size_t>;
        map<int, vector<Position>> position;
        size_t m = grid.size(), n = grid[0].size();
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                position[grid[i][j]].emplace_back(i, j);
            }
        }
        int maxScore = INT_MIN;
        for (auto left = position.begin(); left != position.end(); ++left) {
            for (auto right = --position.end(); right != --position.begin(); --right) {
                for (const auto& position1 : left->second) {
                    for (const auto& position2 : right->second) {
                        if (position1 != position2 &&
                            position1.first <= position2.first &&
                            position1.second <= position2.second) {
                            if (maxScore < right->first - left->first) {
                                cout << "From (" << position1.first << ", " << position1.second << ")"
                                    << " To (" << position2.first << ", " << position2.second << ")" << endl;
                            }
                            maxScore = max(maxScore, right->first - left->first);
                        }
                    }
                }
            }
        }
        return maxScore;
    }
};
