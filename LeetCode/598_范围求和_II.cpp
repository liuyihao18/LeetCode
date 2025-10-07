// 598_��Χ���_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        return accumulate(ops.begin(), ops.end(), m, [](int m, const auto& op) {
            return min(op[0], m);
            })* accumulate(ops.begin(), ops.end(), n, [](int n, const auto& op) {
                return min(op[1], n);
                });
        /**
        * ����Ϊϸ������
        * ���Բ���ѭ��չ���ӿ��ٶ�
        int min_m = m;
        int min_n = n;
        for (const auto& op : ops) {
            min_m = min(op[0], min_m);
        }
        for (const auto& op : ops) {
            min_n = min(op[1], min_n);
        }
        return min_m * min_n;
        */
    }
};