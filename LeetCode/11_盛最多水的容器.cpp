// 11_盛最多水的容器.cpp
#include "custom.h"
ustd

#define INDEX(i) static_cast<size_t>(i)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = static_cast<int>(height.size());
        int left = 0, right = n - 1;
        auto getArea = [&](int left, int right) {
            return (right - left) * min(height[INDEX(left)], height[INDEX(right)]);
            };
        int maxArea = 0;
        while (left < right) {
            maxArea = max(maxArea, getArea(left,right));
            if (height[INDEX(left)] < height[INDEX(right)]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxArea;
    }
};
