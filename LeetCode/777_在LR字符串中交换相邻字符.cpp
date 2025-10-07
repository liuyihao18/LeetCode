// 777_在LR字符串中交换相邻字符.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = static_cast<int>(start.length());
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') {
                i++;
            }
            while (j < n && end[j] == 'X') {
                j++;
            }
            if (i < n && j < n) {
                if (start[i] != end[j]) {
                    return false;
                }
                char c = start[i];
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        while (i < n) {
            if (start[i] != 'X') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (end[j] != 'X') {
                return false;
            }
            j++;
        }
        return true;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/swap-adjacent-in-lr-string/solution/zai-lrzi-fu-chuan-zhong-jiao-huan-xiang-rjaw8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
