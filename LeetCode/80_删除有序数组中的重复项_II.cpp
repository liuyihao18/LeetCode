// 80_ɾ�����������е��ظ���_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t i = 0;
        for (int num : nums) {
            if (i < 2 || num > nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
