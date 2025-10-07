// 691_��ֽƴ��.cpp
#include "stdafx.h"
ustd

// TODO: ״ѹdp
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
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/stickers-to-spell-word/solution/tie-zhi-pin-ci-by-leetcode-solution-9g3z/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
