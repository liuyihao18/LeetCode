// 719_找出第K小的数对距离.cpp
#include "custom.h"
ustd

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size()), left = 0, right = nums.back() - nums.front();
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                int i = static_cast<int>(lower_bound(nums.begin(), nums.begin() + j, nums[j] - mid) - nums.begin());
                cnt += j - i;
            }
            if (cnt >= k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/find-k-th-smallest-pair-distance/solution/zhao-chu-di-k-xiao-de-shu-dui-ju-chi-by-xwfgf/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
