// 1460_ͨ����ת������ʹ�����������.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
