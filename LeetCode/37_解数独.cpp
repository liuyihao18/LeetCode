// 37_解数独.cpp
#include "stdafx.h"
ustd

#define CHECK_ONCE

constexpr size_t NUM_SIZE = 9;
constexpr size_t ROW_SIZE = 9;
constexpr size_t COL_SIZE = 9;
constexpr size_t SQUARE_SIZE = 3;
constexpr size_t SQUARE_ROW_SIZE = ROW_SIZE / SQUARE_SIZE;
constexpr size_t SQUARE_COL_SIZE = COL_SIZE / SQUARE_SIZE;

class Sudoku
{
    using Position = std::pair<size_t, size_t>;

public:
    Sudoku();
    bool Solve();

protected:
    virtual void InitializeConstraints();
    virtual bool CheckOnce(const std::vector<Position>& spaces);
    virtual bool DFS(const std::vector<Position>& spaces, size_t pos = 0);
    virtual bool SatisfyConstraints(size_t i, size_t j, int num);
    virtual void AddConstraints(size_t i, size_t j, int num);
    virtual void RemoveConstraints(size_t i, size_t j, int num);
    virtual int GetCandidateCount(size_t i, size_t j, int& TargetNum);

protected:
    std::vector<int> RowConstraints;
    std::vector<int> ColConstraints;
    std::vector<int> SquareConstraints;
    inline size_t K(size_t i, size_t j) const { return i * COL_SIZE + j; }
    inline size_t I(size_t k) const { return k / COL_SIZE; }
    inline size_t J(size_t k) const { return k % COL_SIZE; }
    inline size_t SquareK(size_t i, size_t j) const;
    std::vector<Position> GetSpaces();
    bool CheckRowConstraints(size_t i, size_t j, int num);
    bool CheckColConstraints(size_t i, size_t j, int num);
    bool CheckSquareConstraints(size_t i, size_t j, int num);
    void AddRowConstraints(size_t i, size_t j, int num);
    void AddColConstraints(size_t i, size_t j, int num);
    void AddSquareConstraints(size_t i, size_t j, int num);
    void RemoveRowConstraints(size_t i, size_t j, int num);
    void RemoveColConstraints(size_t i, size_t j, int num);
    void RemoveSquareConstraints(size_t i, size_t j, int num);

private:
    std::vector<int> Board;

public:
    int& operator()(size_t i, size_t j);
    const int& operator()(size_t i, size_t j) const;
    int& operator[](size_t k);
    const int& operator[](size_t k) const;
    void Read(const std::vector<vector<char>>& board);
    void Write(std::vector<vector<char>>& board) const;
    friend std::istream& operator>>(std::istream& in, Sudoku& sudoku);
    friend std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku);
};

static_assert(ROW_SIZE == NUM_SIZE);
static_assert(COL_SIZE == NUM_SIZE);
static_assert(ROW_SIZE == SQUARE_SIZE * SQUARE_ROW_SIZE);
static_assert(COL_SIZE == SQUARE_SIZE * SQUARE_COL_SIZE);
static_assert(SQUARE_SIZE* SQUARE_SIZE == NUM_SIZE);

Sudoku::Sudoku() : Board(ROW_SIZE* COL_SIZE, 0),
RowConstraints(ROW_SIZE, 0), ColConstraints(COL_SIZE, 0),
SquareConstraints(SQUARE_SIZE* SQUARE_SIZE, 0)
{
}

bool Sudoku::Solve()
{
    InitializeConstraints();
    bool answer = true;
#ifdef CHECK_ONCE
    if (!CheckOnce(GetSpaces()))
    {
        answer = false;
        std::cerr << "*** 数独无解 ***" << std::endl;
    }
#endif
    if (!DFS(GetSpaces()))
    {
        answer = false;
        std::cerr << "*** 数独无解 ***" << std::endl;
    }
    return answer;
}

void Sudoku::InitializeConstraints()
{
    for (size_t i = 0; i < ROW_SIZE; i++)
    {
        for (size_t j = 0; j < COL_SIZE; j++)
        {
            int Num = Board[K(i, j)];
            RowConstraints[i] |= 1 << Num;
            ColConstraints[j] |= 1 << Num;
            SquareConstraints[SquareK(i, j)] |= 1 << Num;
        }
    }
}

bool Sudoku::CheckOnce(const std::vector<Position>& spaces)
{
    while (true)
    {
        bool Update = false;
        for (auto&& [i, j] : spaces)
        {
            if (Board[K(i, j)])
            {
                continue;
            }
            int TargetNum = 0;
            int Count = GetCandidateCount(i, j, TargetNum);
            if (Count == 1)
            {
                Board[K(i, j)] = TargetNum;
                AddConstraints(i, j, TargetNum);
                Update = true;
            }
            else if (Count == 0)
            {
                return false;
            }
        }
        if (!Update)
        {
            break;
        }
    }
    return true;
}

bool Sudoku::DFS(const std::vector<Position>& spaces, size_t pos)
{
    if (pos == spaces.size())
    {
        return true;
    }
#ifdef CHECK_ONCE
    auto Restore = [&]
        {
            size_t n = spaces.size();
            for (size_t p = pos; p < n; p++)
            {
                auto&& [i, j] = spaces[p];
                if (Board[K(i, j)])
                {
                    RemoveConstraints(i, j, Board[K(i, j)]);
                    Board[K(i, j)] = 0;
                }
            }
        };
#endif
    auto&& [i, j] = spaces[pos];
#ifdef CHECK_ONCE
    if (!CheckOnce(spaces))
    {
        return false;
    }
    if (Board[K(i, j)])
    {
        return DFS(spaces, pos + 1);
    }
#endif
    for (int Num = 1; Num <= NUM_SIZE; Num++)
    {
        if (!SatisfyConstraints(i, j, Num))
        {
            continue;
        }
        Board[K(i, j)] = Num;
        AddConstraints(i, j, Num);
        if (DFS(spaces, pos + 1))
        {
            return true;
        }
#ifdef CHECK_ONCE
        Restore();
#else
        RemoveConstraints(i, j, Num);
        Board[K(i, j)] = 0;
#endif
    }
    return false;
}

bool Sudoku::SatisfyConstraints(size_t i, size_t j, int num)
{
    return !CheckRowConstraints(i, j, num) && !CheckColConstraints(i, j, num) && !CheckSquareConstraints(i, j, num);
}

void Sudoku::AddConstraints(size_t i, size_t j, int num)
{
    AddRowConstraints(i, j, num);
    AddColConstraints(i, j, num);
    AddSquareConstraints(i, j, num);
}

void Sudoku::RemoveConstraints(size_t i, size_t j, int num)
{
    RemoveRowConstraints(i, j, num);
    RemoveColConstraints(i, j, num);
    RemoveSquareConstraints(i, j, num);
}

int Sudoku::GetCandidateCount(size_t i, size_t j, int& TargetNum)
{
    int Count = 0;
    for (int Num = 1; Num <= NUM_SIZE; Num++)
    {
        if (SatisfyConstraints(i, j, Num))
        {
            Count++;
            TargetNum = Num;
        }
    }
    return Count;
}

inline size_t Sudoku::SquareK(size_t i, size_t j) const
{
    size_t SquareI = i / SQUARE_SIZE;
    size_t SquareJ = j / SQUARE_SIZE;
    size_t SquareK = SquareI * SQUARE_COL_SIZE + SquareJ;
    return SquareK;
}

std::vector<Sudoku::Position> Sudoku::GetSpaces()
{
    std::vector<Position> Spaces;
    for (size_t i = 0; i < ROW_SIZE; i++)
    {
        for (size_t j = 0; j < COL_SIZE; j++)
        {
            if (!Board[K(i, j)])
            {
                Spaces.emplace_back(i, j);
            }
        }
    }
    std::sort(Spaces.begin(), Spaces.end(), [this](Position p1, Position p2) {
        int DevNull = 0;
        return GetCandidateCount(p1.first, p1.second, DevNull) < GetCandidateCount(p2.first, p2.second, DevNull);
        });
    return Spaces;
}

bool Sudoku::CheckRowConstraints(size_t i, size_t j, int num)
{
    return RowConstraints[i] & (1 << num);
}

bool Sudoku::CheckColConstraints(size_t i, size_t j, int num)
{
    return ColConstraints[j] & (1 << num);
}

bool Sudoku::CheckSquareConstraints(size_t i, size_t j, int num)
{
    return SquareConstraints[SquareK(i, j)] & (1 << num);
}

void Sudoku::AddRowConstraints(size_t i, size_t j, int num)
{
    RowConstraints[i] |= (1 << num);
}

void Sudoku::AddColConstraints(size_t i, size_t j, int num)
{
    ColConstraints[j] |= (1 << num);
}

void Sudoku::AddSquareConstraints(size_t i, size_t j, int num)
{
    SquareConstraints[SquareK(i, j)] |= (1 << num);
}

void Sudoku::RemoveRowConstraints(size_t i, size_t j, int num)
{
    RowConstraints[i] &= ~(1 << num);
}

void Sudoku::RemoveColConstraints(size_t i, size_t j, int num)
{
    ColConstraints[j] &= ~(1 << num);
}

void Sudoku::RemoveSquareConstraints(size_t i, size_t j, int num)
{
    SquareConstraints[SquareK(i, j)] &= ~(1 << num);
}

int& Sudoku::operator()(size_t i, size_t j)
{
    return Board[K(i, j)];
}

const int& Sudoku::operator()(size_t i, size_t j) const
{
    return Board[K(i, j)];
}

int& Sudoku::operator[](size_t k)
{
    return Board[k];
}

const int& Sudoku::operator[](size_t k) const
{
    return Board[k];
}

void Sudoku::Read(const std::vector<vector<char>>& board)
{
    for (size_t i = 0; i < ROW_SIZE; i++)
    {
        for (size_t j = 0; j < COL_SIZE; j++)
        {
            Board[K(i, j)] = board[i][j] == '.' ? 0 : board[i][j] - '0';
        }
    }
}

void Sudoku::Write(std::vector<vector<char>>& board) const
{
    for (size_t i = 0; i < ROW_SIZE; i++)
    {
        for (size_t j = 0; j < COL_SIZE; j++)
        {
            board[i][j] = Board[K(i, j)] == 0 ? '.' : Board[K(i, j)] + '0';
        }
    }
}

std::istream& operator>>(std::istream& in, Sudoku& sudoku)
{
    for (size_t k = 0; k < ROW_SIZE * COL_SIZE; k++)
    {
        in >> sudoku[k];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku)
{
    for (size_t i = 0; i < ROW_SIZE; i++)
    {
        for (size_t j = 0; j < COL_SIZE; j++)
        {
            out << sudoku(i, j) << " ";
        }
        out << std::endl;
    }
    return out;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Sudoku sudoku;
        sudoku.Read(board);
        sudoku.Solve();
        sudoku.Write(board);
    }
};

/*
/class Solution {
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
*/
