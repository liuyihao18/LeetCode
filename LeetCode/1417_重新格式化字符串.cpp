// 1417_重新格式化字符串.cpp
#include "stdafx.h"
ustd

class Solution {
    inline string combine(const string& s1, const string& s2) {
        // assert (s1.size() <= s2.size());
        string res;
        size_t i;
        for (i = 0; i < s1.size(); i++) (res += s2[i]) += s1[i];
        if (i < s2.size()) res += s2.back();
        return res;
    }
public:
    string reformat(string s) {
        string alphas, digits;
        for (auto c : s) if (isalpha(c)) alphas += c; else digits += c;
        if (alphas.size() == digits.size()) return combine(alphas, digits);
        else if (alphas.size() + 1 == digits.size()) return combine(alphas, digits);
        else if (alphas.size() == digits.size() + 1) return combine(digits, alphas);
        else return ""s;
    }
};
