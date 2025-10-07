// 2070_每一个查询的最大美丽值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](const vector<int>& item1, const vector<int>& item2) {
            return item1[0] < item2[0] || item1[0] == item2[0] && item1[1] > item2[1];
            });
        int maximumBeauty = 0;
        map<int, int> maximumBeauties;
        for (size_t i = 0; i < items.size(); i++) {
            int price = items[i][0];
            maximumBeauty = max(maximumBeauty, items[i][1]);
            maximumBeauties[price] = maximumBeauty;
        }
        vector<int> results;
        for (auto query : queries) {
            auto iter = maximumBeauties.upper_bound(query);
            if (iter == maximumBeauties.begin()) {
                results.push_back(0);
                continue;
            }
            --iter;
            results.push_back(iter->second);
        }
        return results;
    }
};
