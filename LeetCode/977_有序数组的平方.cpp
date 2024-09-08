// 977_有序数组的平方.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        transform(nums.begin(), nums.end(), back_inserter(result), [](int num) { return num * num; });
        sort(result.begin(), result.end());
        return result;
    }
};
