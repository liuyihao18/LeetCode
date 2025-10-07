// 1317_将整数转换为两个无零整数的和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n - i;
            if (to_string(i).find('0') == string::npos && 
                to_string(j).find('0') == string::npos) {
                return { i,j };
            }
        }
        return { -1,-1 };
    }
};
