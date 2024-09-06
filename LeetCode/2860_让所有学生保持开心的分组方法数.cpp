// 2860_让所有学生保持开心的分组方法数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countWays(vector<int>& nums) {
        map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        int ways = 0;
        int cnts = 0;
        if (m.begin()->first > 0) {
            ways++;
        }
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            cnts += iter->second;
            if (cnts > iter->first && (next(iter) == m.end() || cnts < next(iter)->first)) {
                ways++;
            }
        }
        return ways;
    }
};
