// 442_�������ظ�������.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        for (size_t i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                result.push_back(nums[i]);
                i++;
            }
        }
        return result;
    }
};


/*
* ԭ��Hash
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1]; // ���ű�ʾ���ֹ�
            }
            else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode-cn.com/problems/find-all-duplicates-in-an-array/solution/shu-zu-zhong-zhong-fu-de-shu-ju-by-leetc-782l/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
