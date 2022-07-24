// 1184_公交站间的距离.cpp
#include "custom.h"
ustd

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int start_dis{ 0 }, destination_dis{ 0 }, total_dis{ 0 };
        for (size_t i = 0; i < distance.size(); i++) {
            if (i == start) start_dis = total_dis;
            if (i == destination) destination_dis = total_dis;
            total_dis += distance[i];
        }
        int diff_dis = abs(start_dis - destination_dis);
        return min(diff_dis, total_dis - diff_dis);
    }
};
