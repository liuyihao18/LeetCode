// 36_有效的数独.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool validRows(const vector<vector<char>>& board) {
        for (const auto& row : board) {
            array<bool, 9> appeared{};
            for (auto num : row) {
                if (num == '.') {
                    continue;
                }
                if (appeared[static_cast<size_t>(num) - '0' - 1]) {
                    return false;
                }
                else {
                    appeared[static_cast<size_t>(num) - '0' - 1] = true;
                }
            }
        }
        return true;
    }
    bool validColumns(const vector<vector<char>>& board) {
        for (size_t j = 0; j < board[0].size(); j++) {
            array<bool, 9> appeared{};
            for (size_t i = 0; i < board.size(); i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (appeared[static_cast<size_t>(board[i][j]) - '0' - 1]) {
                    return false;
                }
                else {
                    appeared[static_cast<size_t>(board[i][j]) - '0' - 1] = true;
                }
            }
        }
        return true;
    }
    bool validSquares(const vector<vector<char>>& board) {
        for (size_t i = 0; i < board.size(); i+=3) {
            for (size_t j = 0; j < board[i].size(); j+=3) {
                if (!validSquare(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool validSquare(const vector<vector<char>>& board, size_t origin_i, size_t origin_j) {
        array<bool, 9> appeared{};
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                if (board[origin_i + i][origin_j + j] == '.') {
                    continue;
                }
                if (appeared[static_cast<size_t>(board[origin_i + i][origin_j + j]) - '0' - 1]) {
                    return false;
                }
                else {
                    appeared[static_cast<size_t>(board[origin_i + i][origin_j + j]) - '0' - 1] = true;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return validRows(board) && validColumns(board) && validSquares(board);
    }
};