// 3488_距离最小相等元素查询.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> solveQueries(const vector<int>& nums, const vector<int>& queries) {
        unordered_map<int, vector<int>> um;
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++)
        {
            um[nums[i]].push_back(i);
        }
        vector<int> results;
        for (const int query: queries)
        {
            vector<int>& index = um[nums[query]];
            if (index.size() == 1)
            {
                results.push_back(-1);
                continue;
            }
            auto iter = ranges::lower_bound(index, query);
            int minDistance = INT_MAX;
            if (iter == index.begin())
            {
                auto other = index.rbegin();
                minDistance = min(minDistance, query + n - *other);
            }
            else
            {
                auto other = iter - 1;
                minDistance = min(minDistance, query - *other);
            }
            if (iter + 1 == index.end())
            {
                auto other = index.begin();
                minDistance = min(minDistance, *other + n - query);
            }
            else
            {
                auto other = iter + 1;
                minDistance = min(minDistance, *other - query);
            }
            results.push_back(minDistance);
        }
        return results;
    }
};
