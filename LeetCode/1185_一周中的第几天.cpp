// 1185_一周中的第几天.cpp
#include "stdafx.h"
ustd

class Solution {
    const string num2str[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
public:
    string dayOfTheWeek(int day, int month, int year) {
        tm t{};
        t.tm_year = year - 1900;
        t.tm_mon = month - 1;
        t.tm_mday = day;
        mktime(&t);
        return num2str[t.tm_wday];
    }
};
