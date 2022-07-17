// 565_Êý×éÇ¶Ì×.cpp
#include "custom.h"
ustd

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLength = 0;
        vector<int> visited(nums.size(), false);
        for (size_t i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            size_t j = i;
            int length = 0;
            while (!visited[j]) {
                length++;
                visited[j] = true;
                j = nums[j];
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
