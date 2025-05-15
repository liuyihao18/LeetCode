// 2900_最长相邻不相等子序列_I.cpp
#include "custom.h"
ustd

class Solution {
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups, int begin) {
        size_t n = groups.size();
        vector<string> results;        
        for (size_t i = 0; i < n; i++) {
            if (groups[i] == begin) {
                results.push_back(words[i]);
                begin = 1 - begin;
            }
        }
        return results;
    }
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> results0 = getLongestSubsequence(words, groups, 0);
        vector<string> results1 = getLongestSubsequence(words, groups, 1);
        return results0.size() < results1.size() ? results1 : results0;
    }
};
