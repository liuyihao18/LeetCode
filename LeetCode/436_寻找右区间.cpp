// 436_я╟урсргЬ╪Д.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> starts;
        int n = static_cast<int>(intervals.size());
        for (int i = 0; i < n; i++) {
            if (!starts.count(intervals[i].front())) {
                starts[intervals[i].front()] = i;
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            auto iter = starts.lower_bound(intervals[i].back());
            if (iter == starts.end()) {
                result.push_back(-1);
            }
            else {
                result.push_back(iter->second);
            }
        }
        return result;
    }
};
