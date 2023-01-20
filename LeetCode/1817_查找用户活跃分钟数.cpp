// 1817_查找用户活跃分钟数.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> m;
        for (const auto& log : logs) {
            m[log[0]].insert(log[1]);
        }
        vector<int> answer(k, 0);
        for (const auto& p : m) {
            answer[p.second.size() - 1]++;
        }
        return answer;
    }
};
