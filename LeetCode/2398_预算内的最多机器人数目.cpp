// 2398_预算内的最多机器人数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int res = 0, n = chargeTimes.size();
        long long runningCostSum = 0;
        deque<int> q;
        int i = 0, j = 0;
        while (i < n) {
            runningCostSum += runningCosts[i];
            while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[i]) {
                q.pop_back();
            }
            q.push_back(i);
            while (j <= i && (i - j + 1) * runningCostSum + chargeTimes[q.front()] > budget) {
                if (q.front() == j) {
                    q.pop_front();
                }
                runningCostSum -= runningCosts[j];
                j++;
            }
            res = max(res, i - j + 1);
            i++;
        }
        return res;
    }
};
