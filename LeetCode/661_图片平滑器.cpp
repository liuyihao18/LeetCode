// 661_Í¼Æ¬Æ½»¬Æ÷.cpp
#include "custom.h"
ustd

const int dirs[][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 0},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

class Solution {
    int filter(const vector<vector<int>>& img, size_t i, size_t j) {
        size_t m = img.size();
        size_t n = img.front().size();
        int count = 0;
        int total = 0;
        for (auto dir : dirs) {
            size_t _i = i + dir[0];
            size_t _j = j + dir[1];
            if (0 <= _i && _i < m && 0 <= _j && _j < n) {
                count++;
                total += img[_i][_j];
            }
        }
        return total / count;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        size_t m = img.size();
        size_t n = img.front().size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                result[i][j] = filter(img, i, j);
            }
        }
        return result;
    }
};
