// 1601_最多可达成的换楼请求数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int result = 0;
        unsigned total_sets = 1 << requests.size();
        for (unsigned subset = 1; subset <= total_sets; subset++) {
            vector<int> degree(n, 0);
            int count = 0;
            for (size_t i = 0; i < requests.size(); i++) {
                if (subset & (1 << i)) {
                    count++;
                    degree[requests[i][0]]--;
                    degree[requests[i][1]]++;
                }
            }
            if (all_of(degree.begin(), degree.end(), [](int num) { return num == 0; })) {
                result = max(result, count);
            }
        }
        return result;
    }
};
