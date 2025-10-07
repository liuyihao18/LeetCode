// 804_Î¨Ò»Ä¦¶ûË¹ÃÜÂë´Ê.cpp
#include "stdafx.h"
ustd

const string char2str[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for (const auto& word : words) {
            string code;
            for (auto c : word) {
                code += char2str[c - 'a'];
            }
            s.insert(code);
        }
        return static_cast<int>(s.size());
    }
};
