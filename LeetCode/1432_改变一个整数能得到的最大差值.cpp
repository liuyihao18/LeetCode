// 1432_改变一个整数能得到的最大差值.cpp
#include "stdafx.h"
ustd

class Solution {
    string replace(const string& str, const char src, const char des) {
        string result;
        for (const char c : str) {
            if (c == src) {
                result += des;
            }
            else {
                result += c;
            }
        }
        return result;
    }
    int getA(int num) {
        const string num_str = to_string(num);
        char a_src = '9';
        for (size_t i = 0; i < num_str.size(); i++) {
            if (num_str[i] != '9') {
                a_src = num_str[i];
                break;
            }
        }
        const char a_des = '9';
        string a_str = replace(num_str, a_src, a_des);
        return stoi(a_str);
    }
    int getB(int num) {
        const string num_str = to_string(num);
        char b_src = '0';
        char b_des = '0';
        string b_str = num_str;
        if (num_str[0] != '1') {
            b_src = num_str[0];
            b_des = '1';
            b_str = replace(num_str, b_src, b_des);
        }
        else {
            for (size_t i = 1; i < num_str.size(); i++) {
                if (num_str[i] != '0') {
                    b_src = num_str[i];
                    b_des = '0';
                    string temp = replace(num_str, b_src, b_des);
                    if (temp[0] != '0') {
                        b_str = std::move(temp);
                        break;
                    }
                }
            }
        }
        return stoi(b_str);
    }

public:
    int maxDiff(int num) {
        int a = getA(num);
        int b = getB(num);
        return a - b;
    }
};
