// 1288_删除被覆盖区间.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 按区间长度排序
        ranges::sort(intervals, [](const vector<int>& interval1, const vector<int>& interval2) {
            return interval1[1] - interval1[0] > interval2[1] - interval2[0];
            });
        map<int, int> m;
        for (const vector<int>& interval : intervals) {
            auto iter = m.upper_bound(interval[0]);
            // 找到第一个区间，其左端点小于等于interval[0]
            if (iter != m.begin()) {
                --iter;
                // 可以证明，这个区间的右端点一定大于其左侧的区间，否则这个区间就被其左侧的区间覆盖
                // 如果这个区间右端点大于等于interval[1]，则当前区间被覆盖
                if (iter->second >= interval[1]) {
                    continue;
                }
            }
            // 填入新区间
            m[interval[0]] = interval[1];
        }
        // 返回区间的数量
        return static_cast<int>(m.size());
    }
};
