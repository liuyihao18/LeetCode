// 1374_����ÿ���ַ��������������ַ���.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string generateTheString(int n) {
        if (n & 1) {
            return string(n, 'a');
        }
        else {
            return string(n - 1, 'a') + 'b';
        }
    }
};
