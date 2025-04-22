// 3144_分割字符频率相等的最少子字符串.cpp
#include "custom.h"
ustd

class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int minimumSubstringsInPartition(string s) {
        int n = static_cast<int>(s.size());
        vector<int> d(n + 1, inf); // d[i]表示以i结尾的前缀字符串划分平衡字符串的最少个数
        unordered_map<char, int> occ_cnt;
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            int max_cnt = 0;
            occ_cnt.clear();
            for (int j = i; j >= 1; j--) {
                occ_cnt[s[j - 1]]++;
                max_cnt = max(max_cnt, occ_cnt[s[j - 1]]);
                // 判断是否是平衡字符串等价于“所有字符出现次数等于出现最多的字符次数”，约化为一个乘法
                if (max_cnt * occ_cnt.size() == (i - j + 1) && d[j - 1] != inf) {
                    d[i] = min(d[i], d[j - 1] + 1); // 转移方程，从后向前计算，若s[i]到s[j]之间构成平衡字符串
                }
            }
        }
        return d[n];
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency/solutions/2886822/fen-ge-zi-fu-pin-lu-xiang-deng-de-zui-sh-ofpv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
