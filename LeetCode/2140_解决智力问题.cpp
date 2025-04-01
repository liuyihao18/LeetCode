// 2140_解决智力问题.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        size_t n = questions.size();
        vector<long long> dp(n, 0);
        map<size_t, long long> m;
        m[0] = 0;
        for (size_t i = 0; i < n; i++) {
            decltype(m)::iterator iter = --m.upper_bound(i);
            dp[i] = iter->second + questions[i][0];
            size_t j = i + questions[i][1] + 1;
            if (j < n) {
                decltype(m)::iterator iter = --m.upper_bound(j);
                if (iter->second < dp[i]) {
                    m[j] = dp[i];
                    decltype(m)::iterator iter = ++m.find(j);
                    while (iter != m.end() && iter->second < dp[i]) {
                        iter = m.erase(iter);
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
