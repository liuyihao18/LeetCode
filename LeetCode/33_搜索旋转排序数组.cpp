// 33_ËÑË÷Ğı×ªÅÅĞòÊı×é.cpp
#include "stdafx.h"
ustd

class Solution {
    int bSearch(const vector<int>& nums, const int target, const int left, const int right) // [left, right]
    {
        if (left > right)
        {
            return -1;
        }
        const int mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            return bSearch(nums, target, mid + 1, right);
        }
        if (nums[mid] > target)
        {
            return bSearch(nums, target, left, mid - 1);
        }
        return mid;
    }
    int search(const vector<int>& nums, const int target, const int left, const int right)
    {
	    if (left > right)
	    {
            return -1;
	    }
        const int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // ×ó°ë±ßÓĞĞò
        if (nums[left] <= nums[mid])
        {
            if (const int res = bSearch(nums, target, left, mid - 1) ;
                res != -1)
            {
                return res;
            }
            return search(nums, target, mid + 1, right);
        }
        // ÓĞ°ë±ßÓĞĞò
        else
        {
            if (const int res = bSearch(nums, target, mid + 1, right);
                res != -1)
            {
                return res;
            }
            return search(nums, target, left, mid - 1);
        }
    }

public:
    int search(const vector<int>& nums, const int target) {
        return search(nums, target, 0, static_cast<int>(nums.size() - 1));
    }
};
