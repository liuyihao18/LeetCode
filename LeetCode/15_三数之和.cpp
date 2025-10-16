// 15_三数之和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (size_t i = 0; i + 2 < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int num1 = nums[i];
            /* 使用双指针，复杂度O(n^2) */
            size_t j = i + 1, k = n - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                int num2 = nums[j], num3 = nums[k];
                if (num1 + num2 + num3 == 0) {
                    ans.push_back({ num1, num2, num3 });
                    j++;
                    k--;
                }
                else if (num1 + num2 + num3 < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
            /* 使用二分查找，复杂度O(n^2 logn)
            for (size_t j = i + 1; j + 1 < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int num2 = nums[j];
                int num3 = -num1 - num2;
                auto iter = lower_bound(nums.begin() + j + 1, nums.end(), num3);
                if (iter != nums.end() && *iter == num3) {
                    ans.push_back({ num1, num2, num3 });
                }
            }
            */
        }
        return ans;
    }
};

/*
class Solution {
private:
    long long hash(long long a, long long b, long long c) {
        return a << 40 | b << 20 | c;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<long long, vector<int>> ans;
        for (size_t i = 0; i + 2 < n; i++) {
            int num1 = nums[i];
            for (size_t j = i + 1; j + 1 < n; j++) {
                int num2 = nums[j];
                int num3 = -num1 - num2;
                auto iter = lower_bound(nums.begin() + j + 1, nums.end(), num3);
                if (iter != nums.end() && *iter == num3 && !ans.count(hash(num1, num2, num3))) {
                    ans[hash(num1, num2, num3)] = { num1, num2, num3 };
                }
            }
        }
        // 把ans的value放入vector
        vector<vector<int>> result;
        for (const auto& [key, value] : ans) {
            result.push_back(value);
        }
        return result;
    }
};
*/

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (size_t first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            size_t third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (size_t second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({ nums[first], nums[second], nums[third] });
                }
            }
        }
        return ans;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/3sum/solutions/284681/san-shu-zhi-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
