// 2559_统计范围内的元音字符串数.cpp
#include "stdafx.h"
ustd

class Solution {
    bool check(const string& word) {
        if (word.empty()) return false;
        return (word.front() == 'a' || word.front() == 'e' || word.front() == 'i' || word.front() == 'o' || word.front() == 'u')
            && (word.back() == 'a' || word.back() == 'e' || word.back() == 'i' || word.back() == 'o' || word.back() == 'u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> diff = { 0 };
        int cnt = 0;
        for (const auto& word : words) {
            if (check(word)) {
                cnt++;
            }
            diff.push_back(cnt);
        }
        vector<int> result;
        for (const auto& query : queries) {
            result.push_back(diff[query.back() + 1] - diff[query.front()]);
        }
        return result;
    }
};
