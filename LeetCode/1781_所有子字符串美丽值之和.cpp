// 1781_所有子字符串美丽值之和.cpp
#include "custom.h"
ustd

class Solution {
public:
    int beautySum(string s) {
        int result = 0;
        for (size_t i = 0; i< s.size(); i++) {
            vector<int> v(26, 0);
            for (size_t j = i; j < s.size(); j++) {
                v[s[j] - 'a']++;
                int minCnt = INT_MAX, maxCnt = 0;
                for (size_t k = 0; k < v.size(); k++) {
                    if (v[k] > 0) {
                        minCnt = min(minCnt, v[k]);
                        maxCnt = max(maxCnt, v[k]);
                    }
                }
                result += maxCnt - minCnt;
            }
        }
        return result;
    }
};
