// 3494_����ҩˮ��Ҫ��������ʱ��.cpp
#include "stdafx.h"
ustd

// ������
class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        size_t n = skill.size(), m = mana.size();
        vector<ll> times(n);
        for (size_t j = 0; j < m; j++) {
            ll cur_time = 0;
            for (size_t i = 0; i < n; i++) {
                cur_time = max(cur_time, times[i]) + 1LL * skill[i] * mana[j];
            }
            times[n - 1] = cur_time;
            for (size_t i = n - 2; i != -1; i--) {
                times[i] = times[i + 1] - 1LL * skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/find-the-minimum-amount-of-time-to-brew-potions/solutions/3800529/niang-zao-yao-shui-xu-yao-de-zui-shao-zo-ojii/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
