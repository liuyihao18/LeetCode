// 442_数组中重复的数据.cpp
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
* 原地Hash
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1]; // 负号表示出现过
            }
            else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/find-all-duplicates-in-an-array/solution/shu-zu-zhong-zhong-fu-de-shu-ju-by-leetc-782l/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
