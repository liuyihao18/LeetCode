// 2100_适合打劫银行的日子.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> downtimes(security.size(), 0);
        vector<int> uptimes(security.size(), 0);
        size_t n = security.size();
        for (size_t i = 1; i < n; i++) {
            if (security[i] - security[i - 1] <= 0) {
                downtimes[i] = downtimes[i - 1] + 1;
            }
            if (security[n - i - 1] - security[n - i] <= 0) {
                uptimes[n - i - 1] = uptimes[n - i] + 1;
            }
        }
        vector<int> result;
        for (size_t i = time; i + time < n; i++) {
            if (downtimes[i] >= time && uptimes[i] >= time) {
                result.push_back(static_cast<int>(i));
            }
        }
        return result;
    }
};
