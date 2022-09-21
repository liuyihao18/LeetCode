// 854_相似度为K的字符串.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minSwap(const string& s1, const string& s2, const int& pos) {
        int tot = 0;
        for (int i = pos; i < s1.size(); i++) {
            tot += s1[i] != s2[i];
        }
        return (tot + 1) / 2;
    }

    int kSimilarity(string s1, string s2) {
        using State = tuple<int, int, int, string>;
        int n = static_cast<int>(s1.size());
        priority_queue<State, vector<State>, greater<State>> pq;
        unordered_set<string> visit;
        pq.emplace(0, 0, 0, s1);
        visit.emplace(s1);
        while (!pq.empty()) {
            auto [_, cost, pos, cur] = pq.top();
            pq.pop();
            if (cur == s2) {
                return cost;
            }
            while (pos < n && cur[pos] == s2[pos]) {
                pos++;
            }
            for (int j = pos + 1; j < n; j++) {
                if (s2[j] == cur[j]) {
                    continue;
                }
                if (s2[pos] == cur[j]) {
                    swap(cur[pos], cur[j]);
                    if (!visit.count(cur)) {
                        visit.emplace(cur);
                        pq.emplace(cost + 1 + minSwap(s2, cur, pos + 1), cost + 1, pos + 1, cur);
                    }
                    swap(cur[pos], cur[j]);
                }
            }
        }
        return 0;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/k-similar-strings/solution/xiang-si-du-wei-k-de-zi-fu-chuan-by-leet-8z10/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
