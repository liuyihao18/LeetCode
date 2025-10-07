// 2325_½âÃÜÏûÏ¢.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> table(26, 0);
        char target = 'a';
        for (size_t i = 0; i < key.size() && target <= 'z'; i++) {
            if (key[i] != ' ' && table[key[i] - 'a'] == 0) 
                table[key[i] - 'a'] = target++;
        }
        for (auto& c : message) {
            if (c != ' ') c = table[c - 'a'];
        }
        return message;
    }
};
