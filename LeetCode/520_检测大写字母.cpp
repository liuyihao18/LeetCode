// 520_¼ì²â´óÐ´×ÖÄ¸.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1) {
            return true;
        }
        bool first_cap = word.front() >= 'A' && word.front() <= 'Z';
        bool rest_cap = *(word.begin() + 1) >= 'A' && *(word.begin() + 1) <= 'Z';
        for (auto iter = word.begin() + 2; iter != word.end(); ++iter) {
            if (*iter >= 'A' && *iter <= 'Z') {
                if (!rest_cap) {
                    return false;
                }
            }
            else {
                if (rest_cap) {
                    return false;
                }
            }
        }
        return !(!first_cap && rest_cap);
    }
};