// 709_×ª»»³ÉÐ¡Ð´×ÖÄ¸.cpp
#include "custom.h"
ustd

class Solution {
public:
    string toLowerCase(string s) {
        string result;
        transform(s.begin(), s.end(), back_inserter(result), [](char c) {
            return tolower(c);
            });
        return result;
    }
};
