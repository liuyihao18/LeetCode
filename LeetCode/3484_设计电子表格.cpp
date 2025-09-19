// 3484_设计电子表格.cpp
#include "custom.h"
ustd

class Spreadsheet {
private:
    vector<int> table;
    int& operator[](const string& cell) {
        int col = static_cast<size_t>(cell[0] - 'A');
        int row = stoi(cell.substr(1)) - 1;
        int index = row * 26 + col;
        return table[index];
    }
    const int& operator[](const string& cell) const {
        int col = static_cast<size_t>(cell[0] - 'A');
        int row = stoi(cell.substr(1)) - 1;
        int index = row * 26 + col;
        return table.at(index);
    }

public:
    Spreadsheet(int rows) : table(rows * 26) {
        
    }

    void setCell(string cell, int value) {
        (*this)[cell] = value;
    }

    void resetCell(string cell) {
        (*this)[cell] = 0;
    }

    int getValue(string formula) {
        size_t pos = formula.find('+');
        string x = formula.substr(1, pos - 1);
        string y = formula.substr(pos + 1);
        int xValue = 0;
        int yValue = 0;
        if (x[0] >= 'A' && x[0] <= 'Z') {
            xValue = (*this)[x];
        }
        else {
            xValue = stoi(x);
        }
        if (y[0] >= 'A' && y[0] <= 'Z') {
            yValue = (*this)[y];
        }
        else {
            yValue = stoi(y);
        }
        return xValue + yValue;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
