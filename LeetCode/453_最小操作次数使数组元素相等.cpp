// 453_��С��������ʹ����Ԫ�����.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = *min_element(nums.begin(), nums.end());
        int result = 0;
        for (auto num : nums) {
            result += num - min_num;
        }
        return result;
    }
};