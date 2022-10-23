// 1768_½»ÌæºÏ²¢×Ö·û´®.cpp
#include "custom.h"
ustd

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t l = min(word1.size(), word2.size());
        string result;
        for (size_t i = 0; i < l; i++) {
            result += word1[i];
            result += word2[i];
        }
        for (size_t i = l; i < word1.size(); i++) {
            result += word1[i];
        }
        for (size_t i = l; i < word2.size(); i++) {
            result += word2[i];
        }
        return result;
    }
};
