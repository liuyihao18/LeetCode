// 58_���һ�����ʵĳ���.cpp
#include "custom.h"
ustd

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream is(s);
        string word;
        while (is >> word);
        return word.length();
    }
};