// 剑指_Offer_II_069_山峰数组的顶部.cpp
#include "custom.h"
ustd

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size();
        int mid = (left + right) / 2;
        while (right - left > 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                break;
            }
            if (arr[mid] <= arr[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        return mid;
        // return partition_point(arr.begin() + 1, arr.end() - 1, [](auto&& x) {return *((&x) + 1) > x; }) - arr.begin();
    }
};
