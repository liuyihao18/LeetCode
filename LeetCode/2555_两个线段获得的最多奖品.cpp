// 2555_�����߶λ�õ���ཱƷ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = static_cast<int>(prizePositions.size());
        vector<int> dp(n + 1);  // �Ҷ˵㲻���� prizePositions[i]��һ������Ϊ k ���߶������Ը��ǵĽ�Ʒ���������
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = static_cast<int>(lower_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k) - prizePositions.begin());
            ans = max(ans, i - x + 1 + dp[x]);
            dp[i + 1] = max(dp[i], i - x + 1);
        }
        return ans;
    }
};

