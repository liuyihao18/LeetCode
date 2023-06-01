// 2517_礼盒的最大甜蜜度.cpp
#include "custom.h"
ustd

class Solution {
    bool check(const vector<int>& price, int k, int m) {
        int prev = INT_MIN >> 1;
        int cnt = 0;
        for (size_t i = 0; i < price.size(); i++) {
            if ((price[i] - prev) >= m) {
                cnt++;
                prev = price[i];
            }
        }
        return cnt >= k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = price.back() - price.front() + 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (check(price, k, m)) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l - 1;
    }
};
