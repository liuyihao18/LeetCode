// 167_两数之和_II_输入有序数组.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        auto iter1 = numbers.begin();
        while (iter1 != numbers.end()) {
            auto iter2 = upper_bound(numbers.begin(), numbers.end(), target - *iter1);
            --iter2;
            if (iter2 != numbers.end() && iter2 != iter1 && *iter2 + *iter1 == target) {
                return {
                    static_cast<int>(distance(numbers.begin(), iter1)) + 1,
                    static_cast<int>(distance(numbers.begin(), iter2)) + 1
                };
            }
            ++iter1;
        }
        return { -1,-1 };
    }
};
