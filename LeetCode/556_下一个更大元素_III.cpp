// 556_下一个更大元素_III.cpp
#include "stdafx.h"
ustd

// TODO: 下一个排列
class Solution {
public:
    int nextGreaterElement(int n) {
        auto&& s = to_string(n);
        return !next_permutation(s.begin(), s.end()) || stol(s) > INT_MAX ? -1 : stoi(s);
    }
};
