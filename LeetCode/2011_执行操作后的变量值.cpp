// 2011_ִ�в�����ı���ֵ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const auto& operation : operations) {
            if (operation == "X++" || operation == "++X") {
                x++;
            }
            else {
                x--;
            }
        }
        return x;
    }
};
