// 1154_一年中的第几天.cpp
#include "stdafx.h"
ustd

class Solution {
    int string2int(const string& str) {
        int result = 0;
        istringstream in(str);
        in >> result;
        return result;
    }
    const int normalDays[12] { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334  };
public:
    int dayOfYear(const string& date) {
        /*
        tm t{};
        t.tm_year = stoi(date.substr(0, 4));
        t.tm_mon = stoi(date.substr(5, 2)) - 1;
        t.tm_mday = stoi(date.substr(8, 2));
        mktime(&t);
        return t.tm_yday + 1;
        */
        int year = string2int(date.substr(0, 4));
        int month = string2int(date.substr(5, 2));
        int day = string2int(date.substr(8, 2));
        bool isLeapYear = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
        int dayOfYear = normalDays[month - 1] + day;
        if (month > 2 && isLeapYear) {
            dayOfYear++;
        }
        return dayOfYear;
    }
};
