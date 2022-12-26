// 1739_放置盒子.cpp
#include "custom.h"
ustd

class Solution {
public:
    int g(int x) {
        return (long long)x * (x + 1) * (x + 2) / 6;
    }

    int minimumBoxes(int n) {
        int i = static_cast<int>(pow(6.0 * n, 1.0 / 3));
        if (g(i) < n) {
            i++;
        }
        n -= g(i - 1);
        int j = static_cast<int>(ceil(1.0 * (sqrt((long long)8 * n + 1) - 1) / 2));
        return (i - 1) * i / 2 + j;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/building-boxes/solutions/2030450/fang-zhi-he-zi-by-leetcode-solution-7ah2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
