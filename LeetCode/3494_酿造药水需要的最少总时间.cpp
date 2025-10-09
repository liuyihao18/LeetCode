// 3494_����ҩˮ��Ҫ��������ʱ��.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        size_t n = skill.size();
        size_t m = mana.size();
        long long skillSum = accumulate(skill.begin(), skill.end(), 0LL);
        long long manaSum = accumulate(mana.begin(), mana.end(), 0LL);
        long long result = skillSum * manaSum;
        for (size_t i = 1; i < m; i++) {
            long long overlap = 0;
            long long timestamp1 = 0, timestamp2 = 0;
            for (size_t j = n - 1; j > 0; j--) {
                timestamp1 = timestamp1 - 1LL * mana[i - 1] * skill[j];
                timestamp2 = timestamp2 - 1LL * mana[i] * skill[j - 1];
                if (timestamp2 < timestamp1) {
                    overlap += timestamp1;
                    timestamp1 = 0;
                    timestamp2 = 0;
                }
            }
            overlap += timestamp2;
            result += overlap;
        }
        return result;
    }
};

/*
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
