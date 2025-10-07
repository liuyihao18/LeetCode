// 37_解数独.cpp
#include "stdafx.h"
ustd

class Solution {
    void removeCandidateByPosition(const vector<vector<char>>& board, vector<vector<set<char>>>& candidates, size_t i, size_t j, char c) {
        // 去除第i行的候选项
        for (size_t k = 0; k < 9; k++) {
            if (board[i][k] == '.') {
                candidates[i][k].erase(c);
            }
        }
        // 去除第j列的候选项
        for (size_t k = 0; k < 9; k++) {
            if (board[k][j] == '.') {
                candidates[k][j].erase(c);
            }
        }
        // 去除方格内的候选项
        size_t squareI = i / 3, squareJ = j / 3;
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                if (board[3 * squareI + i][3 * squareJ + j] == '.') {
                    candidates[3 * squareI + i][3 * squareJ + j].erase(c);
                }
            }
        }
    }
    void addCandidateByPosition(const vector<vector<char>>& board, vector<vector<set<char>>>& candidates, size_t i, size_t j, char c) {
        // 加上第i行的候选项
        for (size_t k = 0; k < 9; k++) {
            if (board[i][k] == '.') {
                candidates[i][k].insert(c);
            }
        }
        // 加上第j列的候选项
        for (size_t k = 0; k < 9; k++) {
            if (board[k][j] == '.') {
                candidates[k][j].insert(c);
            }
        }
        // 加上方格内的候选项
        size_t squareI = i / 3, squareJ = j / 3;
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                if (board[3 * squareI + i][3 * squareJ + j] == '.') {
                    candidates[3 * squareI + i][3 * squareJ + j].insert(c);
                }
            }
        }
    }

    vector<vector<set<char>>> computeCandidates(const vector<vector<char>>& board) {
        size_t row = 9, col = 9;
        vector<vector<set<char>>> candidates(9, vector<set<char>>(9));
        for (size_t i = 0; i < 9; i++) {
            for (size_t j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        candidates[i][j].insert(c);
                    }
                }
            }
        }
        // 去除候选项
        for (size_t i = 0; i < 9; i++) {
            for (size_t j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    removeCandidateByPosition(board, candidates, i, j, board[i][j]);
                }
            }
        }
        return candidates;
    }

    bool backtrace(vector<vector<char>>& board, vector<vector<set<char>>> candidates) {
        bool needBacktrace = false;
        // 先不回溯填写
        while (!needBacktrace) {
            bool flag = false;
            for (size_t i = 0; i < 9; i++) {
                for (size_t j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        if (candidates[i][j].size() == 1) {
                            board[i][j] = *candidates[i][j].begin();
                            removeCandidateByPosition(board, candidates, i, j, board[i][j]);
                            flag = true;
                            break;
                        }
                        else if (candidates[i][j].size() == 0) {
                            return false;
                        }
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (!flag) {
                needBacktrace = true;
            }
        }
#ifdef DEBUG
        cout << "--------------- 直接填写 -----------------" << endl;
        for (const vector<char>& row : board) {
            for (char c : row) {
                cout << c << " ";
            }
            cout << endl;
        }
#endif
        // 然后回溯填写
        for (size_t i = 0; i < 9; i++) {
            for (size_t j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c : candidates[i][j]) {
                        vector<vector<char>> tempBoard = board;
                        vector<vector<set<char>>> tempCandidates = candidates;
                        tempBoard[i][j] = c;
                        removeCandidateByPosition(tempBoard, tempCandidates, i, j, tempBoard[i][j]);
#ifdef DEBUG
                        cout << "--------------- 回溯填写 -----------------" << endl;
                        for (const vector<char>& row : tempBoard) {
                            for (char c : row) {
                                cout << c << " ";
                            }
                            cout << endl;
                        }
#endif
                        if (backtrace(tempBoard, tempCandidates)) {
                            board = tempBoard;
                            candidates = tempCandidates;
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<set<char>>> candidates = computeCandidates(board);
        // 回溯
#ifdef DEBUG
        cout << "--------------- 初始棋盘 -----------------" << endl;
        for (const vector<char>& row : board) {
            for (char c : row) {
                cout << c << " ";
            }
            cout << endl;
        }
#endif
        backtrace(board, candidates);
    }
};

int mian() {
#define BOARD3
#ifdef BOARD1
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
#endif
#ifdef BOARD2
    vector<vector<char>> board = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };
#endif
#ifdef BOARD3
    vector<vector<char>> board = {
        {'.','.','.','2','.','.','.','6','3'},
        {'3','.','.','.','.','5','4','.','1'},
        {'.','.','1','.','.','3','9','8','.'},
        {'.','.','.','.','.','.','.','9','.'},
        {'.','.','.','5','3','8','.','.','.'},
        {'.','3','.','.','.','.','.','.','.'},
        {'.','2','6','3','.','.','5','.','.'},
        {'5','.','3','7','.','.','.','.','8'},
        {'4','7','.','.','.','1','.','.','.'}
    };
#endif
    Solution solution;
    solution.solveSudoku(board);
#ifdef DEBUG
    cout << "--------------- 最终结果 -----------------" << endl;
    for (const vector<char>& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}
