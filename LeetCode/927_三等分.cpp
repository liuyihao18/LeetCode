// 927_三等分.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) {
            return { -1, -1 };
        }
        if (sum == 0) {
            return { 0, 2 };
        }

        int partial = sum / 3;
        int first = 0, second = 0, third = 0, cur = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                if (cur == 0) {
                    first = i;
                }
                else if (cur == partial) {
                    second = i;
                }
                else if (cur == 2 * partial) {
                    third = i;
                }
                cur++;
            }
        }

        int len = (int)arr.size() - third;
        if (first + len <= second && second + len <= third) {
            int i = 0;
            while (third + i < arr.size()) {
                if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i]) {
                    return { -1, -1 };
                }
                i++;
            }
            return { first + len - 1, second + len };
        }
        return { -1, -1 };
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/three-equal-parts/solution/san-deng-fen-by-leetcode-solution-3l2y/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
