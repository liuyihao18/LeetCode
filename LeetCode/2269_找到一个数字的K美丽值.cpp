// 2269_找到一个数字的K美丽值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numStr = to_string(num);
        int result = 0;
        for (size_t i = 0; i + k <= numStr.size(); i++) {
            string subStr = numStr.substr(i, k);
            int sub = stoi(subStr);
            if (sub != 0 && num % sub == 0) {
                result++;
            }
        }
        return result;
    }
};
