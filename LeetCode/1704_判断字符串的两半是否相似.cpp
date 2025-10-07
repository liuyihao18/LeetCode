// 1704_判断字符串的两半是否相似.cpp
#include "stdafx.h"
ustd

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
    }
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        for (size_t i = 0; i < s.size() / 2; i++) {
            s[i] = tolower(s[i]);
            if (isVowel(s[i])) {
                cnt++;
            }
        }
        for (size_t i = s.size() / 2; i < s.size(); i++) {
            s[i] = tolower(s[i]);
            if (isVowel(s[i])) {
                cnt--;
            }
        }
        return cnt == 0;
    }
};
