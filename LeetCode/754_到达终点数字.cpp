// 754_�����յ�����.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = static_cast<int>(ceil((-1 + sqrt(8L * target + 1)) / 2)); // ע�� 8*target �ᳬ�� int ��Χ
        return (n * (n + 1) / 2 - target) % 2 == 0 ? n : n + 1 + n % 2;
    }
};
/*
���ߣ�endlesscheng
���ӣ�https ://leetcode.cn/problems/reach-a-number/solution/fen-lei-tao-lun-xiang-xi-zheng-ming-jian-sqj2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
