// 1460_通过翻转子数组使两个数组相等.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
