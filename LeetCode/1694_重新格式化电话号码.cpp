// 1694_重新格式化电话号码.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string reformatNumber(string number) {
        string temp;
        for (auto num : number) {
            if (isdigit(num)) {
                temp += num;
            }
        }
        string result;
        size_t i = 0;
        for (; i + 4 < temp.size(); i += 3) {
            result += temp[i];
            result += temp[i + 1];
            result += temp[i + 2];
            result += '-';
        }
        if (temp.size() - i == 2) {
            result += temp[i];
            result += temp[i + 1];
        }
        else if (temp.size() - i == 3) {
            result += temp[i];
            result += temp[i + 1];
            result += temp[i + 2];
        }
        else {
            result += temp[i]; 
            result += temp[i + 1]; 
            result += '-';
            result += temp[i + 2];
            result += temp[i + 3];
        }
        return result;
    }
};
