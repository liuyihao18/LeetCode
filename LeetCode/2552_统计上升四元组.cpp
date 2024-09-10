// 2552_ͳ��������Ԫ��.cpp
#include "custom.h"
ustd

// ��Ŀ�����ˣ������������������������
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp2(n, 0); // ������Ԫ��
        vector<int> dp3(n, 0); // ������Ԫ��
        vector<int> dp4(n, 0); // ������Ԫ��
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
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/count-increasing-quadruplets/solutions/2909099/tong-ji-shang-sheng-si-yuan-zu-by-leetco-0g7g/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
