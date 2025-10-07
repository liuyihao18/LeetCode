// 2042_�������е������Ƿ����.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool areNumbersAscending(string s) {
        s += ' ';
        string temp;
        int lastNumber = -1;
        for (auto c : s) {
            if (c != ' ') {
                temp += c;
            }
            else {
                if (temp.size() > 0 && isdigit(temp[0])) {
                    int number = stoi(temp);
                    if (number <= lastNumber) {
                        return false;
                    }
                    lastNumber = number;
                }
                temp.clear();
            }
        }
        return true;
    }
};
