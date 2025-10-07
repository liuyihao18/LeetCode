// 2299_«ø√‹¬ÎºÏ—È∆˜_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }
        if (all_of(password.begin(), password.end(), [](char c) {
            return !(c <= 'z' && c >= 'a');
            })) {
            return false;
        }
        if (all_of(password.begin(), password.end(), [](char c) {
            return !(c <= 'Z' && c >= 'A');
            })) {
            return false;
        }
        if (all_of(password.begin(), password.end(), [](char c) {
            return !(c <= '9' && c >= '0');
            })) {
            return false;
        }
        string symbol = "!@#$%^&*()-+";
        if (all_of(password.begin(), password.end(), [&](char c) {
            return symbol.find(c) == string::npos;
            })) {
            return false;
        }
        for (size_t i = 0; i + 1 < password.size(); i++) {
            if (password[i] == password[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
