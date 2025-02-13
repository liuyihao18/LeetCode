// 42_接雨水.cpp
#include "custom.h"
ustd

class Solution {
private:
    vector<int>::iterator my_max_element_first(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) {
            return end;
        }
        vector<int>::iterator iter = begin;
        while (begin != end) {
            if (*begin > *iter) {
                iter = begin;
            }
            ++begin;
        }
        return iter;
    }
    vector<int>::iterator my_max_element_last(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) {
            return end;
        }
        vector<int>::iterator iter = begin;
        while (begin != end) {
            if (*begin >= *iter) {
                iter = begin;
            }
            ++begin;
        }
        return iter;
    }
    int trapLeft(vector<int>& height, vector<int>::iterator right) {
        if (right == height.begin()) {
            return 0;
        }
        auto left = my_max_element_first(height.begin(), right);
        int base = accumulate(left + 1, right, 0);
        int ans = min(*left, *right) * (static_cast<int>(distance(left, right)) - 1) - base;
        return ans + trapLeft(height, left);
    }
    int trapRight(vector<int>& height, vector<int>::iterator left) {
        if (left + 1 == height.end()) {
            return 0;
        }
        auto right = my_max_element_last(left + 1, height.end());
        int base = accumulate(left + 1, right, 0);
        int ans = min(*left, *right) * (static_cast<int>(distance(left, right)) - 1) - base;
        return ans + trapRight(height, right);
    }
public:
    int trap(vector<int>& height) {
        auto middle = max_element(height.begin(), height.end());
        // 期望复杂度：2 * T(n / 2)
        // 期望递推式：T(n / 2) = T(n / 4) + O(n / 2) \Rightarrow T(n) = T(n/2) + O(n) \Rightarrow T(n) = O(n)
        // 故期望复杂度：2 * T(n / 2） = O(n)
        // 最差复杂度：T(n - 1) + T(1)
        // 最差递推式：T(n) = T(n - 1) + O(n) \Rightarrow T(n) = O(n^2)
        // 故最差复杂度：T(n - 1) + T(1) = O(n^2)
        return trapLeft(height, middle) + trapRight(height, middle);
    }
};

/*
class Solution {
public:
    int trap(vector<int>& height) {
        size_t n = height.size(), i = 0, j = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (i < j) {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            if (leftMax < rightMax) {
                ans += leftMax - height[i];                
                i++;
            }
            else {
                ans += rightMax - height[j];
                j--;
            }
        }
        return ans;
    }
};
*/
