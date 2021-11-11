// 638_�����.cpp
#include "custom.h"
ustd

class Solution {
public:
    map<vector<int>, int> memo;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        size_t n = price.size();

        // ���˲���Ҫ����Ĵ������ֻ������Ҫ����Ĵ����
        vector<vector<int>> filterSpecial;
        for (auto& sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (size_t i = 0; i < n; ++i) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if (totalCount > 0 && totalPrice > sp[n]) {
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, special, needs, filterSpecial, n);
    }

    // ���仯�����������㹺���嵥���軨�ѵ���ͼ۸�
    int dfs(vector<int> price, const vector<vector<int>>& special, vector<int> curNeeds, vector<vector<int>>& filterSpecial, size_t n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; ++i) {
                minPrice += curNeeds[i] * price[i]; // �������κδ������ԭ�۹������嵥�е�������Ʒ
            }
            for (auto& curSpecial : filterSpecial) {
                int specialPrice = curSpecial[n];
                vector<int> nxtNeeds;
                for (int i = 0; i < n; ++i) {
                    if (curSpecial[i] > curNeeds[i]) { // ���ܹ��򳬳������嵥ָ����������Ʒ
                        break;
                    }
                    nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
                }
                if (nxtNeeds.size() == n) { // ��������Թ���
                    minPrice = min(minPrice, dfs(price, special, nxtNeeds, filterSpecial, n) + specialPrice);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
};
