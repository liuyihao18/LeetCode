// 1235_规划兼职工作.cpp
#include "custom.h"
ustd

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = static_cast<int>(startTime.size());
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = { startTime[i], endTime[i], profit[i] };
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2) -> bool {
            return job1[1] < job2[1];
            });
        vector<int> dp(n + 1);
        for (size_t i = 1; i <= n; i++) {
            ptrdiff_t k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
                return st < job[1];
                }) - jobs.begin();
                dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/maximum-profit-in-job-scheduling/solution/gui-hua-jian-zhi-gong-zuo-by-leetcode-so-gu0e/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
