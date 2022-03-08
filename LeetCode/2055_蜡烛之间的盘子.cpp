// 2055_蜡烛之间的盘子.cpp
#include "custom.h"
ustd

class Solution {
public:
    // TLE
    /*
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<size_t> poses;
        vector<int> counts;
        size_t last_pos = s.find_first_of('|');
        size_t curr_pos = s.find_first_of('|', last_pos + 1);
        while (curr_pos != string::npos) {
            poses.push_back(last_pos);
            counts.push_back(static_cast<int>(curr_pos - last_pos - 1));
            last_pos = curr_pos;
            curr_pos = s.find_first_of('|', last_pos + 1);
        }
        if (last_pos != string::npos) {
            poses.push_back(last_pos);
        }
        map<pair<size_t, size_t>, int> dp;
        for (size_t i = 0; i + 1 < poses.size(); i++) {
            dp[make_pair(i, i + 1)] = counts[i];
        }
        for (size_t i = 0; i + 1 < poses.size(); i++) {
            for (size_t l = 2; i + l < poses.size(); l++) {
                dp[make_pair(i, i + l)] = dp[make_pair(i, i + l - 1)] + dp[make_pair(i + l - 1, i + l)];
            }
        }
        vector<int> result;
        if (poses.size() < 2) {
            for (const auto& query : queries) {
                result.push_back(0);
            }
        }
        else {
            for (const auto& query : queries) {
                auto iter1 = lower_bound(poses.begin(), poses.end(), query[0]);
                auto iter2 = --upper_bound(poses.begin(), poses.end(), query[1]);
                if (iter1 == poses.end() || iter2 == poses.end()) {
                    result.push_back(0);
                    continue;
                }
                size_t pos1 = distance(poses.begin(), iter1);
                size_t pos2 = distance(poses.begin(), iter2);
                result.push_back(dp[make_pair(pos1, pos2)]);
            }
        }
        return result;
    }
    */
    // 其实没那么复杂
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = static_cast<int>(s.length());
        vector<int> preSum(n);
        for (int i = 0, sum = 0; i < n; i++) {
            if (s[i] == '*') {
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
        }
        return ans;
    }
};
