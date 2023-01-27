// 2309_兼具大小写的最好英文字母.cpp
#include "custom.h"
ustd

class Solution {
public:
    string greatestLetter(string s) {
        vector<unsigned> v(26, 0);
        for (auto c : s) {
            if (isupper(c)) {
                v[tolower(c) - 'a'] |= 2;
            }
            else {
                v[c - 'a'] |= 1;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (v[i] == 3) {
                return string() + static_cast<char>(toupper('a' + i));
            }
        }
        return string();
    }
};
