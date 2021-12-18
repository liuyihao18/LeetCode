// 419_¼×°åÉÏµÄÕ½½¢.cpp
#include "custom.h"
ustd

class Solution {
    void erase(vector<vector<char>>& board, size_t i, size_t j) {
        if (board[i][j] == 'X') {
            board[i][j] = '.';
            if (i + 1 < board.size()) {
                erase(board, i + 1, j);
            }
            if (j + 1 < board.at(i).size()) {
                erase(board, i, j + 1);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty()) {
            return 0;
        }
        int res = 0;
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board.at(i).size(); j++) {
                /*
                if (board[i][j] == 'X') {
                    res++;
                    erase(board, i, j);
                }
                */
                if (board[i][j] == 'X' && (!i || board[i - 1][j] == '.') && (!j || board[i][j - 1] == '.')) {
                    res++;
                }
            }
        }
        return res;
    }
};
