// 40_组合总和_II.cpp
#include "custom.h"
ustd

class Solution {
    set<vector<int>> _combinationSum2(map<int, int>& m, int target) {
        set<vector<int>> results;
        auto iter = m.upper_bound(target);
        while (iter != m.begin()) {
            --iter;
            if (iter->second > 0) {
                if (iter->first == target) {
                    results.insert({ target });
                }
                else {
                    --iter->second;
                    set<vector<int>> others = _combinationSum2(m, target - iter->first);
                    for (auto& other : others) {
                        vector<int> temp = other;
                        temp.push_back(iter->first);
                        sort(temp.begin(), temp.end());
                        results.insert(std::move(temp));
                    }
                    ++iter->second;
                }
            }
        }
        return results;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> m;
        for (auto candidate : candidates) {
            m[candidate]++;
        }
        set<vector<int>> results = _combinationSum2(m, target);
        return vector<vector<int>>(results.begin(), results.end());
    }
};
