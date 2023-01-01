// 2351_第一个出现两次的字母.cpp
#include "custom.h"
ustd

class Solution {
public:
    char repeatedCharacter(string s) {
        unsigned int occured = 0;
        for (auto c : s) {
            if (occured & (1 << (c - 'a'))) return c;
            else occured |= (1 << (c - 'a'));
        }
        return -1;
    }
};
