// 556_��һ������Ԫ��_III.cpp
#include "stdafx.h"
ustd

// TODO: ��һ������
class Solution {
public:
    int nextGreaterElement(int n) {
        auto&& s = to_string(n);
        return !next_permutation(s.begin(), s.end()) || stol(s) > INT_MAX ? -1 : stoi(s);
    }
};
