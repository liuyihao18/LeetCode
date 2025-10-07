// 1668_最大重复子字符串.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        for (int k = 1; k < 100; k++) {
            string temp;
            for (int i = 0; i < k; i++) {
                temp += word;
            }
            if (sequence.find(temp) == string::npos) {
                return k - 1;
            }
        }
        return -1;
    }
};
