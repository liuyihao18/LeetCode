// 81_������ת��������_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};
