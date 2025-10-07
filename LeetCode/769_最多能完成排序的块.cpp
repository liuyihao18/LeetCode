// 769_最多能完成排序的块.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        int m = 0, res = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, arr[i]);
            if (m == i) {
                res++;
            }
        }
        return res;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/max-chunks-to-make-sorted/solution/zui-duo-neng-wan-cheng-pai-xu-de-kuai-by-gc4k/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
