// 1636_按照频率将数组升序排序.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        sort(nums.begin(), nums.end(), [&](int num1, int num2) {
            return m[num1] < m[num2] || m[num1] == m[num2] && num1 > num2;
            });
        return nums;
        /*
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second || p1.second == p2.second && p1.first > p2.first;
            });
        vector<int> result;
        for (auto&& [key, val] : v) {
            for (int i = 0; i < val; i++) {
                result.push_back(key);
            }
        }
        return result;
        */
    }
};
