// 2918_数组的最小相等和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        long long count1 = count(nums1.begin(), nums1.end(), 0);
        long long count2 = count(nums2.begin(), nums2.end(), 0);
        if (sum1 + count1 == sum2 + count2) {
            return sum1 + count1;
        }
        else if (sum1 + count1 > sum2 + count2) {
            if (count2 == 0) {
                return -1;
            }
            else {
                return sum1 + count1;
            }
        }
        else {
            if (count1 == 0) {
                return -1;
            }
            else {
                return sum2 + count2;
            }
        }
    }
};
