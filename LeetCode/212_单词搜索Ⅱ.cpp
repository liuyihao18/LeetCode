// 212_单词搜索Ⅱ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool wordAbleInBoard(const string& word, const vector<vector<char>>& board) {
        for (auto iter = word.begin(); iter != word.end(); ++iter) {
            bool found = false;
            for (auto line : board) {
                if (find(line.begin(), line.end(), *iter) != line.end()) {
                    found = true;
                    break;
                }
            }
            if (found == false) {
                return false;
            }
        }
        return true;
    }
    bool wordInBoard(const string& word, vector<vector<char>>& board) {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (word[0] == board[i][j]) {
                    if (dfs(word, 1, board, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool _dfs(const string& word, int index, vector<vector<char>>& board, size_t i, size_t j, size_t new_i, size_t new_j) {
        if (new_i >= 0 && new_i < board.size() && new_j >= 0 && (!board.empty() && new_j < board[0].size())) {
            if (board[new_i][new_j] == word[index]) {
                auto temp = board[i][j]; // 保存现场
                board[i][j] = 0;
                if (dfs(word, index + 1, board, new_i, new_j)) {
                    board[i][j] = temp; // 还原
                    return true;
                }
                else {
                    board[i][j] = temp; // 还原
                    return false;
                }
            }
        }
        return false;
    }
    bool dfs(const string& word, int index, vector<vector<char>>& board, size_t i, size_t j) {
        if (index == word.size()) {
            return true;
        }

        if (_dfs(word, index, board, i, j, i - 1, j)) { // 上
            return true;
        }

        if (_dfs(word, index, board, i, j, i, j - 1)) { // 左
            return true;
        }

        if (_dfs(word, index, board, i, j, i + 1, j)) { // 下
            return true;
        }

        if (_dfs(word, index, board, i, j, i, j + 1)) { // 右
            return true;
        }

        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        for (const auto& word : words) {
            if (wordAbleInBoard(word, board) && wordInBoard(word, board)) {
                result.push_back(word);
            }
        }
        return result;
    }
};