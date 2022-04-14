// 1672_最富有客户的资产总量.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> v;
        transform(accounts.begin(), accounts.end(), back_inserter(v), [](const vector<int>& account) {
            return accumulate(account.begin(), account.end(), 0);
        });
        return *max_element(v.begin(), v.end());
        /*
        return accumulate(max_element(accounts.begin(), accounts.end(), [](const vector<int>& account1, const vector<int>& account2) {
            return accumulate(account1.begin(), account1.end(), 0) < accumulate(account2.begin(), account2.end(), 0);
            })->begin(), max_element(accounts.begin(), accounts.end(), [](const vector<int>& account1, const vector<int>& account2) {
                return accumulate(account1.begin(), account1.end(), 0) < accumulate(account2.begin(), account2.end(), 0);
                })->end(), 0);
         */
    }
};
