// 1921_���������������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double, vector<double>, greater<double>> q;
        for (size_t i = 0; i < dist.size(); i++) {
            q.push(dist[i] * 1.0 / speed[i]);
        }
        int time = 0;
        int eliminate = 0;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (time < t) {
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
