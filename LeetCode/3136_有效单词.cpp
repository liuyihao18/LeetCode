// 3136_ÓÐÐ§µ¥´Ê.cpp
#include "custom.h"
ustd

bool isvowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isconsonant(char c) {
    return isalpha(c) && !isvowel(c);
}

class Solution {
public: 
    bool isValid(string word) {
        auto ck1 = word.size() >= 3;
        auto ck2 = all_of(word.begin(), word.end(), [](char c) { return isalnum(c); });
        auto ck3 = any_of(word.begin(), word.end(), isvowel);
        auto ck4 = any_of(word.begin(), word.end(), isconsonant);
        return ck1 && ck2 && ck3 && ck4;
    }
};
