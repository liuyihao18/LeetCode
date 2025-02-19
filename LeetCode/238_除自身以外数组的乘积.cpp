// 238_除自身以外数组的乘积.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> preProd(n, 1), sufProd(n, 1);
        for (size_t i = 1; i < n; i++) {
            preProd[i] = preProd[i - 1] * nums[i - 1];
        }
        for (size_t i = n - 2; i != -1; i--) {
            sufProd[i] = sufProd[i + 1] * nums[i + 1];
        }
        vector<int> answer(n, 1);
        for (size_t i = 0; i < n; i++) {
            answer[i] = preProd[i] * sufProd[i];
        }
        return answer;
    }
};
