// 792_匹配子序列的单词数.cpp
#include "stdafx.h"
ustd

// TLE
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        for (const auto& word : words) {
            size_t i = 0, j = 0;
            while (i < s.size() && j < word.size()) {
                if (s[i] == word[j]) {
                    i++;
                    j++;
                }
                else {
                    i++;
                }
            }
            if (j == word.size()) {
                result++;
            }
        }
        return result;
    }
};
/*
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (auto& w : words) {
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            int p = -1;
            for (char c : w) {
                auto& ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {
                    --res;
                    break;
                }
                p = *it;
            }
        }
        return res;
    }
};
*/
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/number-of-matching-subsequences/solutions/1973995/pi-pei-zi-xu-lie-de-dan-ci-shu-by-leetco-vki7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
