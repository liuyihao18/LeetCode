// 753_�ƽⱣ����.cpp
#include "stdafx.h"
ustd

class Solution {
private:
    unordered_set<int> seen;
    string ans;
    int highest;
    int k;

public:
    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int nei = node * 10 + x;
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }

    string crackSafe(int n, int k) {
        highest = static_cast<int>(pow(10, n - 1));
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/cracking-the-safe/solutions/393529/po-jie-bao-xian-xiang-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
