// 769_������������Ŀ�.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        int m = 0, res = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, arr[i]);
            if (m == i) {
                res++;
            }
        }
        return res;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/max-chunks-to-make-sorted/solution/zui-duo-neng-wan-cheng-pai-xu-de-kuai-by-gc4k/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
