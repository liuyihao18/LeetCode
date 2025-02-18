// 189_ÂÖ×ªÊý×é.cpp
#include "custom.h"
ustd

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        k %= n;
        int index = gcd(n, k);
        for (int i = 0; i < index; i++) {
            int j = i;
            int temp = nums[j];
            do {
                nums[j] = nums[static_cast<size_t>((j - k + n) % n)];
                j = (j - k + n) % n;
            } while (j != i);
            nums[static_cast<size_t>((j + k) % n)] = temp;
        }
    }
};

/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
        vector<int> temp(n, 0);
        for (size_t i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};
*/
