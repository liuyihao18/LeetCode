// 2016_����Ԫ��֮�������ֵ.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                result = max(result, nums[j] - nums[i]);
            }
        }
        return result ? result : -1;
    }
    /*
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            }
            else {
                premin = nums[i];
            }
        }
        return ans;
    }
    /*
    ���ߣ�LeetCode - Solution
    ���ӣ�https ://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/solution/zeng-liang-yuan-su-zhi-jian-de-zui-da-ch-i0wk/
    ��Դ�����ۣ�LeetCode��
    ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
    */
};
