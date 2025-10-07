// 2073_买票需要的时间.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int need = tickets[k];
        int time = 0;
        for (size_t i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                time += min(need, tickets[i]);
            }
            else {
                time += min(need - 1, tickets[i]);
            }
        }
        return time;
    }
};
