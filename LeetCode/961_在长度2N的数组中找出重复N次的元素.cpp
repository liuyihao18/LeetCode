// 961_�ڳ���2N���������ҳ��ظ�N�ε�Ԫ��.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for (auto num : nums) {
            if (s.count(num)) {
                return num;
            }
            s.insert(num);
        }
        return -1;
    }
};
