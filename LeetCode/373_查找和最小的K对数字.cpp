// 373_查找和最小的K对数字.cpp
#include "stdafx.h"
ustd

class Solution {
    struct CMP {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        vector<pair<int,int>> ps;
        for (auto num1 : nums1) {
            for (auto num2 : nums2) {
                ps.push_back({ num1,num2 });
            }
        }
        sort(ps.begin(), ps.end(), CMP());
        for (size_t i = 0; i < ps.size() && i < k; i++) {
            result.push_back({ ps[i].first, ps[i].second });
        }
        return result;
    }
};

/*
* Following is true!
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        auto cmp = [&](int a, int b) { return nums1[a >> 16] + nums2[a & 0xffff] > nums1[b >> 16] + nums2[b & 0xffff]; };
        vector<vector<int>> ans;
        ans.reserve(min((uint64_t)m * n, (uint64_t)k));
        priority_queue pq{ cmp, vector<int>() };
        for (int i = 0; i < m && i < k; ++i) pq.emplace(i << 16);
        while (!pq.empty() && k--) {
            auto a = pq.top() >> 16, b = pq.top() & 0xffff; pq.pop();
            if (b + 1 < n) pq.emplace((a << 16) + b + 1);
            ans.push_back({ nums1[a], nums2[b] });
        }
        return ans;
    }
};
*/
