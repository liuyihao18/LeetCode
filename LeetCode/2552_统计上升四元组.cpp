// 2552_统计上升四元组.cpp
#include "custom.h"
ustd

// 题目看错了，这个“上升”并不上升啊！
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp2(n, 0); // 上升二元组
        vector<int> dp3(n, 0); // 上升三元组
        vector<int> dp4(n, 0); // 上升四元组
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp2[i]++;
                    dp3[i] += dp2[j];
                    dp4[i] += dp3[j];
                }
            }
        }
        return dp4[n - 1];
    }
};

/*
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            int suf = 0;
            for (int k = n - 1; k > j; --k) {
                if (nums[j] > nums[k]) {
                    ans += static_cast<long long>(pre[nums[k]]) * suf;
                }
                else {
                    ++suf;
                }
            }
            for (int x = nums[j] + 1; x <= n; ++x) {
                ++pre[x];
            }
        }
        return ans;
    }
};
*/
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/count-increasing-quadruplets/solutions/2909099/tong-ji-shang-sheng-si-yuan-zu-by-leetco-0g7g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
