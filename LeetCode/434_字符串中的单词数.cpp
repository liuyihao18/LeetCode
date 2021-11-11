// 434_字符串中的单词数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countSegments(string s) {
        stringstream in(s);
        string word;
        size_t count{ 0 };
        while (in >> word) {
            ++count;
        }
        return static_cast<int>(count);
    }
};