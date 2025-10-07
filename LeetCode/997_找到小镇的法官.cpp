// 997_找到小镇的法官.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findJudge(int n, const vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);
        for (const auto& edge : trust) {
            ++outDegree[edge.front()];
        }
        for (const auto& edge : trust) {
            ++inDegree[edge.back()];
        }
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
