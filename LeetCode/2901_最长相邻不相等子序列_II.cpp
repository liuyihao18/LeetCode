// 2901_最长相邻不相等子序列_II.cpp
#include "custom.h"
ustd

class Solution {
    int hammingDistance(const string& word1, const string& word2) {
        size_t n = word1.size();
        int distance = 0;
        for (size_t i = 0; i < n; i++) {
            distance += word1[i] == word2[i] ? 0 : 1;
        }
        return distance;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        size_t n = words.size();
        vector<size_t> dp(n, 0); // dp[i]表示0..i个字符串的最长子序列的最长长度
        vector<size_t> prev(n, -1); // 转移记录
        size_t maxIndex = 0;
        for (size_t i = 1; i < n; i++) {
            for (size_t j = 0; j < i; j++) {
                if (groups[i] != groups[j] && words[i].size() == words[j].size() && hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }
        vector<string> results;
        for (size_t i = maxIndex; i != -1; i = prev[i]) {
            results.push_back(std::move(words[i]));
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
