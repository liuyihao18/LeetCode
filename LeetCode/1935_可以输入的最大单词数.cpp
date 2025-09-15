// 1935_可以输入的最大单词数.cpp
#include "custom.h"
ustd

constexpr size_t Index(char c) {
    return static_cast<size_t>(c - 'a');
}

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool _brokenLetters[26] = {};
        for (char c : brokenLetters) {
            _brokenLetters[Index(c)] = true;
        }
        int result = -1;
        istringstream iss(text);
        while (iss) {
            string word;
            iss >> word;
            result++;
            for (char c : word) {
                if (_brokenLetters[Index(c)]) {
                    result--;
                    break;
                }
            }
        }
        return result;
    }
};
