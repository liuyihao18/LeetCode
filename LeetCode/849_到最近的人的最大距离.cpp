// 849_到最近的人的最大距离.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<size_t> index;
        for (size_t i = 0; i < seats.size(); i++) {
            if (seats[i]) index.push_back(i);
        }
        int maxDist = 0;
        for (size_t i = 0; i < seats.size(); i++) {
            auto pos = upper_bound(index.begin(), index.end(), i);
            size_t left = INT_MIN / 2, right = INT_MAX / 2;
            if (pos != index.begin()) {
                left = *(pos - 1);
            }
            if (pos == index.end()) {
                right = *pos;
            }
            int dist1 = i - left;
            int dist2 = right - i;
            maxDist = max(maxDist, min(dist1, dist2));
        }
        return maxDist;
    }
};
