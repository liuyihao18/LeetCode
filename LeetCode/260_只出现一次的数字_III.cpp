// 260_只出现一次的数字_III.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = nums[0];
        size_t count = 1;
        vector<int> result;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == last) {
                count++;
            }
            else {  
                if (count == 1) {
                    result.push_back(last);
                }
                last = nums[i];
                count = 1;
            }
        }
        if (count == 1) {
            result.push_back(last);
        }
        return result;
    }
};