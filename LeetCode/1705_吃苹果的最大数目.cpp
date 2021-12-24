// 1705_吃苹果的最大数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<size_t, int> rot_days;
        int res = 0;
        size_t i = 0;
        auto eat = [&](size_t i) {
            if (rot_days.begin() != rot_days.end() && i == rot_days.begin()->first) {
                rot_days.erase(rot_days.begin());
            }
            auto iter = rot_days.begin();
            while (iter != rot_days.end()) {
                if (iter->second > 0) {
                    iter->second--;
                    res++;
                    break;
                }
                else {
                    iter = rot_days.erase(iter);
                }
            }
        };
        for (; i < apples.size(); i++) {
            if (apples[i] > 0) {
                rot_days[i + days[i]] = apples[i];
            }
            eat(i);
        }
        for (; !rot_days.empty();i++) {
            eat(i);
        }
        return res;
    }
};
