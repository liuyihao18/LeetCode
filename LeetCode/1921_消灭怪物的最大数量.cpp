// 1921_消灭怪物的最大数量.cpp
#include "custom.h"
ustd

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (size_t i = 0; i < dist.size(); i++) {
            q.push((dist[i] - 1) / speed[i]);
        }
        int time = 0;
        int eliminate = 0;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (time <= t) {
                eliminate++;
            }
            else {
                break;
            }
            time++;
        }
        return eliminate;
    }
};
