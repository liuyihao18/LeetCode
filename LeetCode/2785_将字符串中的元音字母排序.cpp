// 2785_½«×Ö·û´®ÖÐµÄÔªÒô×ÖÄ¸ÅÅÐò.cpp
#include "custom.h"
ustd

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    string sortVowels(string s) {
        string vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels += c;
            }
        }
        sort(vowels.begin(), vowels.end());
        size_t i = 0;
        for (char& c : s) {
            if (isVowel(c)) {
                c = vowels[i++];
            }
        }
        return s;
    }
};
