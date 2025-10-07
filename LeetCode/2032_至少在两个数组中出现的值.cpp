// 2032_至少在两个数组中出现的值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int, size_t> cnt;
        set<int> temp;
        for (auto num : nums1) {
            if (!temp.count(num)){
                temp.insert(num);
                cnt[num]++;
            }            
        }
        temp.clear();
        for (auto num : nums2) {
            if (!temp.count(num)) {
                temp.insert(num);
                cnt[num]++;
            }
        }
        temp.clear();
        for (auto num : nums3) {
            if (!temp.count(num)) {
                temp.insert(num);
                cnt[num]++;
            }
        }
        vector<int> result;
        for (auto& [key, val] : cnt) {
            if (val > 1) {
                result.push_back(key);
            }
        }
        return result;
    }
};
