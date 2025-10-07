// 599_两个列表的最小索引总和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, size_t> m;
        for (size_t i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }
        vector<string> result;
        size_t minIdxSum = SIZE_MAX;
        for (size_t i = 0; i < list2.size(); i++) {
            if (m.count(list2[i])) {
                size_t idxSum = i + m[list2[i]];
                if (idxSum < minIdxSum) {
                    minIdxSum = idxSum;
                    result.clear();
                    result.push_back(list2[i]);
                }
                else if (idxSum == minIdxSum) {
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};
