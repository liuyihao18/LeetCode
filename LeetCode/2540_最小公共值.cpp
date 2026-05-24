// 2540_最小公共值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int getCommon(const vector<int>& nums1, const vector<int>& nums2) {
        const size_t n1 = nums1.size(), n2 = nums2.size();
    	size_t i = 0, j = 0;
        while (i < n1 && j < n2)
        {
	        if (nums1[i] < nums2[j] )
	        {
                i++;
	        }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                return nums1[i];
            }
        }
        return -1;
    }
};
