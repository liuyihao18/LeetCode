// 794_有效的井字游戏.cpp
#include "custom.h"
ustd

class Solution {
    bool isVaild(const vector<string>& board) {
        // 判满
        bool full = true;
        for (const auto& row : board) {
            if (row.find(' ') != string::npos) {
                full = false;
                break;
            }
        }
        if (full) {
            return false;
        }

        // 胜利
        bool vectory = false;
        // 行
        for (size_t i = 0; i < 3; i++) {
            if (board[i][0] == ' ' || board[i][1] == ' ' || board[i][2] == ' '){
                continue;
            }
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                vectory = true;
            }
        }
        // 列
        for (size_t j = 0; j < 3; j++) {
            if (board[0][j] == ' ' || board[1][j] == ' ' || board[2][j] == ' ') {
                continue;
            }
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                vectory = true;
            }
        }
        // 对角线
        if (board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' ') {
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                vectory = true;
            }
        }
        if (board[2][0] != ' ' && board[1][1] != ' ' && board[0][2] != ' ') {
            if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
                vectory = true;
            }
        }
        if (vectory) {
            return false;
        }

        return true;
    }
    bool dfs(vector<string>& board, const vector<string>& target, int turn) {
        if (board == target) {
            return true;
        }
        if (!isVaild(board)) {
            return false;
        }
        switch (turn) {
        case 1:
            for (size_t i = 0; i < 3; i++) {
                for (size_t j = 0; j < 3; j++) {
                    if (board[i][j] == ' ' && target[i][j] == 'X') {
                        board[i][j] = 'X';
                        if (dfs(board, target, 2)) {
                            return true;
                        }
                        board[i][j] = ' ';
                    }
                }
            }
            break;
        case 2:
            for (size_t i = 0; i < 3; i++) {
                for (size_t j = 0; j < 3; j++) {
                    if (board[i][j] == ' ' && target[i][j] == 'O') {
                        board[i][j] = 'O';
                        if (dfs(board, target, 1)) {
                            return true;
                        }
                        board[i][j] = ' ';
                    }
                }
            }
            break;
        default:
            break;
        }
        return false;
    }
public:
    bool validTicTacToe(const vector<string>& board) {
        vector<string> _board = { "   ", "   ", "   " };
        return dfs(_board, board, 1);
    }
};

/* ??? 真值表牛逼
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt = 0, w[128]{};
        for (auto&& s : board) for (char c : s) cnt += c == 'O' ? -1 : c == 'X';
        for (int i = 0; i < 3; ++i) {
            ++w[board[i][0] | board[i][1] | board[i][2]];
            ++w[board[0][i] | board[1][i] | board[2][i]];
        }
        ++w[board[0][0] | board[1][1] | board[2][2]];
        ++w[board[0][2] | board[1][1] | board[2][0]];
        return cnt == 1 && !w['O'] || cnt == 0 && !w['X'];
    }
};
*/
