// 1282_用户分组.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<vector<int>>> division;
        for (int i = 0; i < static_cast<int>(groupSizes.size()); i++) {
            int groupSize = groupSizes[i];
            vector<int>* ptr = nullptr;
            if (!division.count(groupSize)) {
                division[groupSize].emplace_back();
                ptr = &division[groupSize].back();
            }
            else {
                ptr = &division[groupSize].back();
                if (ptr->size() == groupSize) {
                    division[groupSize].emplace_back();
                    ptr = &division[groupSize].back();
                }
            }
            ptr->push_back(i);
        }
        vector<vector<int>> result;
        for (auto& [key, val] : division) {
            for (auto& group : val) {
                result.push_back(std::move(group));
            }
        }
        return result;
    }
};
