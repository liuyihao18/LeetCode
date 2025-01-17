// 3097_或值至少为K的最短子数组_II.cpp
#include "custom.h"
ustd

void orAdd(vector<int>& bitCount, int num) {
    for (size_t i = 0; i < bitCount.size(); i++) {
        if (num >> i & 1) {
            bitCount[i]++;
        }
    }
}

void orSubtract(vector<int>& bitCount, int num) {
    for (size_t i = 0; i < bitCount.size(); i++) {
        if (num >> i & 1) {
            bitCount[i]--;
        }
    }
}

int toSum(const vector<int>& bitCount) {
    int sum = 0;
    for (size_t i = 0; i < bitCount.size(); i++) {
        if (bitCount[i]) {
            sum |= 1 << i;
        }
    }
    return sum;
}

class Solution {
public:
    int minimumSubarrayLength(const vector<int>& nums, int k) {
        int i = 0, j = 0;
        int length = 88888888;
        vector<int> bitCount(32, 0);
        while (j < nums.size()) {
            orAdd(bitCount, nums[j++]);
            while (i < j && toSum(bitCount) >= k) {
                length = min(length, j - i);
                orSubtract(bitCount, nums[i++]);
            }
        }
        return length >= 88888888 ? -1 : length;
    }
};
