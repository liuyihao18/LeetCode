// 691_贴纸拼词.cpp
#include "stdafx.h"
ustd

// TODO: 状压dp
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = static_cast<int>(target.size());
        int max = 1 << m;
        vector<int> dp(max, -1);
        dp[0] = 0;
        function<int(int)> helper = [&](int mask) {
            if (dp[mask] != -1) {
                return dp[mask];
            }
            dp[mask] = m + 1;
            for (auto& sticker : stickers) {
                int left = mask;
                vector<int> cnt(26);
                for (char& c : sticker) {
                    cnt[c - 'a']++;
                }
                for (int i = 0; i < m; i++) {
                    if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0) {
                        cnt[target[i] - 'a']--;
                        left ^= 1 << i;
                    }
                }
                if (left < mask) {
                    dp[mask] = min(dp[mask], helper(left) + 1);
                }
            }
            return dp[mask];
        };
        int res = helper((1 << m) - 1);
        return res > m ? -1 : res;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/stickers-to-spell-word/solution/tie-zhi-pin-ci-by-leetcode-solution-9g3z/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
