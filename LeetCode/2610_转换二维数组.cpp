// 2610_转换二维数组.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, size_t> counts;
        for (auto num : nums) {
            counts[num]++;
        }
        vector<vector<int>> results;
        while (!counts.empty()) {
            vector<int> result;
            for (auto iter = counts.begin(); iter != counts.end();) {
                result.push_back(iter->first);
                if (--iter->second == 0) {
                    iter = counts.erase(iter);
                }
                else {
                    ++iter;
                }
            }
            results.push_back(result);
        }
        return results;
    }
};
