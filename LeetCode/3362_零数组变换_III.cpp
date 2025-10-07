// 3362_ÁãÊý×é±ä»»_III.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), 
            [](const vector<int>& query1, const vector<int>& query2) {
                return query1[0] < query2[0];
            }
        );
        const size_t n = nums.size(), q = queries.size();
        vector<int> diff(n + 1);
        size_t i = 0, j = 0;
        int sum = 0, noUse = 0;
        priority_queue<int> pq;
        while (i < n) {
            sum -= diff[i];
            while (j < q && queries[j][0] <= i) {
                pq.push(queries[j++][1]);
            }
            while (sum < nums[i] && !pq.empty()) {
                size_t r = pq.top();
                pq.pop();
                if (i <= r) {
                    sum++;
                    diff[r + 1]++;
                }
                else {
                    noUse++;
                }
            }
            if (sum < nums[i++]) {
                return -1;
            }
        }
        return static_cast<int>(pq.size()) + noUse;
    }
};
