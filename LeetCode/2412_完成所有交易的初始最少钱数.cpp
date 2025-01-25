// 2412_������н��׵ĳ�ʼ����Ǯ��.cpp
#include "custom.h"
ustd

/*
WA�������Ҿ�����д�ú�����
*/
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        auto totalLost = accumulate(transactions.begin(), transactions.end(), 0LL,
            [](long long val, const vector<int>& transaction) {
                auto cost = transaction[0], cashback = transaction[1];
                return val + max(cost - cashback, 0);
            });
        auto maxCost = max_element(transactions.begin(), transactions.end(),
            [](const vector<int>& transaction1, const vector<int>& transaction2) {
                auto cost1 = transaction1[0], cashback1 = transaction1[1];
                auto val1 = cost1 < cashback1 ? cost1 : -1;
                auto cost2 = transaction2[0], cashback2 = transaction2[1];
                auto val2 = cost2 < cashback2 ? cost2 : -1;
                return val1 < val2;
            });
        return totalLost + max(maxCost->front(), 0);
    }
};

/*
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long total_lose = 0;
        int res = 0;
        for (auto& t : transactions) {
            auto [cost, cashback] = pair(t[0], t[1]);
            total_lose += max(cost - cashback, 0);
            res = max(res, min(cost, cashback));
        }
        return total_lose + res;
    }
};
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/minimum-money-required-before-transactions/solutions/3047584/wan-cheng-suo-you-jiao-yi-de-chu-shi-zui-cde1/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/