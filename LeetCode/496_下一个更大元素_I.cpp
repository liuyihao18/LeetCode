// 496_下一个更大元素_I.cpp
#include "custom.h"
ustd

class Solution {
public:
#ifdef WRONG
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> orders(10001, 0);
        for_each(nums2.begin(), nums2.end(), [&](int num) {
            orders[num]++; });
        int last = -1;
        for (size_t i = 0; i < orders.size(); i++) {
            if (orders[i] > 0) {
                if (last != -1) {
                    orders[last] = i;
                }
                last = i;
            }
        }
        orders[last] = -1;
        vector<int> result;
        transform(nums1.begin(), nums1.end(), back_inserter(result), [&](int num) {
            return orders[num];
            });
        return result;
    }
#endif
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> orders(10001, 0);
        stack<int> s;
        for (auto iter = nums2.rbegin(); iter != nums2.rend(); ++iter) {
            while (!s.empty() && *iter > s.top()) {
                s.pop();
            }
            if (s.empty()) {
                orders[*iter] = -1;
                s.push(*iter);
            }
            else {
                orders[*iter] = s.top();
                s.push(*iter);
            }
        }
        vector<int> result;
        transform(nums1.begin(), nums1.end(), back_inserter(result), [&](int num) {
            return orders[num];
            });
        return result;
    }
};