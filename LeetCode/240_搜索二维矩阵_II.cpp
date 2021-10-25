// 240_ËÑË÷¶þÎ¬¾ØÕó_II.cpp
#include "custom.h"
ustd

class Solution {
public:
#ifdef DFS
    map<pair<size_t, size_t>, bool> result;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return _searchMatrix(matrix, target, 0, 0);
    }
    bool _searchMatrix(vector<vector<int>>& matrix, int target, size_t i, size_t j) {
        if (result.find({ i,j }) != result.end()) {
            return result[{ i, j }];
        }
        if (i >= matrix.size()) {
            return false;
        }
        if (matrix.size() > 0 && j >= matrix[0].size()) {
            return false;
        }
        if (target == matrix[i][j]) {
            result.insert({ { i,j }, true });
            return true;
        }
        if (target > matrix[i][j]) {
            bool res = _searchMatrix(matrix, target, i + 1, j) || _searchMatrix(matrix, target, i, j + 1);
            result.insert({ { i, j }, res });
            return res;
        }
        result.insert({ { i, j }, false });
        return false;
    }
#elif defined BINARY
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& vec : matrix) {
            if (lower_bound(vec.begin(), vec.end(), target) != vec.end() && *lower_bound(vec.begin(), vec.end(), target) == target) {
                return true;
            }
        }
        return false;
    }
#else 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        pair<size_t, size_t> BST_root = { 0, matrix[0].size() - 1 };
        auto isValid = [&](const pair<size_t, size_t> root) {
            return root.first < matrix.size() && root.second != -1;
        };
        while (isValid(BST_root)) {
            if (matrix[BST_root.first][BST_root.second] == target) {
                return true;
            }
            if (matrix[BST_root.first][BST_root.second] > target) {
                BST_root.second--;  // ×ó×ÓÊ÷
            }
            else {
                BST_root.first++;  // ÓÒ×ÓÊ÷
            }
        }
        return false;
    }
#endif
};