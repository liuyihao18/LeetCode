// 3691_最大子数组总值_II.cpp
#include "stdafx.h"
ustd

// 以下代码是错的
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());

        map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[nums[i]] = i;
        }

        struct State {
            int value;
            decltype(index.begin()) minIter;
            decltype(index.rbegin()) maxIter;
            State(int value, const decltype(index.begin())& minIter, const decltype(index.rbegin())& maxIter)
                : value(value), minIter(minIter), maxIter(maxIter) {
            }
            bool operator<(const State& r) const {
                return value < r.value;
            }
        };

        priority_queue<State> pq;
        pq.emplace(index.rbegin()->first - index.begin()->first,
            index.begin(), index.rbegin());

        long long result = 0;
        int left = -1;
        int right = n;
        int arrayCount = 0;
        while (k > arrayCount && !pq.empty()) {
            State st = pq.top();
            pq.pop();
            const auto& [minValue, minIndex] = *st.minIter;
            const auto& [maxValue, maxIndex] = *st.maxIter;
            auto newMinIter = next(st.minIter);
            auto newMaxIter = next(st.maxIter);
            pq.emplace(st.maxIter->first - newMinIter->first, newMinIter, st.maxIter);
            pq.emplace(newMaxIter->first - st.minIter->first, st.minIter, newMaxIter);
        }
        
        return result;
    }
};
