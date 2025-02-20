// 41_缺失的第一个正数.cpp
#include "custom.h"
ustd

// 原地哈希方法
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t n = nums.size();
        for (size_t i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[static_cast<size_t>(nums[i] - 1)]) {
                    break;
                }
                swap(nums[i], nums[static_cast<size_t>(nums[i] - 1)]);
            }
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return static_cast<int>(i + 1);
            }
        }
        return static_cast<int>(n + 1);
    }
};

/*
* 这个方法无法解决数组中存在重复元素的情况
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t n = nums.size();
        size_t slow = 0;
        for (size_t fast = 0; fast < n; fast++) {
            if (nums[fast] > 0) {
                nums[slow++] = nums[fast];
            }
        }
        nums.erase(nums.begin() + slow, nums.end());
        size_t l = 0, r = nums.size();
        while (l < r) { // [l, r)
            size_t m = (l + r + 1) / 2;  // 选取中间的数
            size_t i = l, j = r - 1;
            // 以这个数为锚点，把比他小的放在他的左边，比他大的放在他的右边
            while (i < j + 1) {
                while (i < j + 1 && nums[i] <= m) {
                    i++;
                }
                while (i < j + 1 && nums[j] > m) {
                    j--;
                }
                if (i < j + 1) {
                    swap(nums[i], nums[j]);
                }
            }
            // 最后nums[i]将大于m，并且nums[i-1]将小于等于m；
            // 如果i等于m，说明1..m-1放在了前m-1个数中，完整；
            // 待找的数应该在右区间；否则找左区间
            if (i == m) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return static_cast<int>(l + 1);
    }
};
*/
