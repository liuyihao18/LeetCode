// 777_��LR�ַ����н��������ַ�.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = static_cast<int>(start.length());
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') {
                i++;
            }
            while (j < n && end[j] == 'X') {
                j++;
            }
            if (i < n && j < n) {
                if (start[i] != end[j]) {
                    return false;
                }
                char c = start[i];
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        while (i < n) {
            if (start[i] != 'X') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (end[j] != 'X') {
                return false;
            }
            j++;
        }
        return true;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/swap-adjacent-in-lr-string/solution/zai-lrzi-fu-chuan-zhong-jiao-huan-xiang-rjaw8/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
