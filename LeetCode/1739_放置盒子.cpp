// 1739_���ú���.cpp
#include "custom.h"
ustd

class Solution {
public:
    int g(int x) {
        return (long long)x * (x + 1) * (x + 2) / 6;
    }

    int minimumBoxes(int n) {
        int i = static_cast<int>(pow(6.0 * n, 1.0 / 3));
        if (g(i) < n) {
            i++;
        }
        n -= g(i - 1);
        int j = static_cast<int>(ceil(1.0 * (sqrt((long long)8 * n + 1) - 1) / 2));
        return (i - 1) * i / 2 + j;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/building-boxes/solutions/2030450/fang-zhi-he-zi-by-leetcode-solution-7ah2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
