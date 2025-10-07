// 551_学生出勤记录_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool checkRecord(string s) {
        bool flag1 = count_if(s.begin(), s.end(), [](char c) { return c == 'A'; }) < 2;
        bool flag2 = s.find("LLL") == string::npos;
        return flag1 && flag2;
    }
};
