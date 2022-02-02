// 2000_反转单词前缀.cpp
#include "custom.h"
ustd

class Solution {
public:
    string reversePrefix(string word, char ch) {
        /*
        size_t pos = word.find(ch);
        if (pos == string::npos) {
            return word;
        }
        size_t mid = pos >> 1;
        for (size_t i = 0; i <= mid; i++) {
            swap(word[i], word[pos - i]);
        }
        */
        reverse(word.begin(), word.begin() + word.find(ch) + 1);
        return word;
    }
};
