// 828_统计子串中的唯一字符.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = static_cast<int>(s.size());
        unordered_map<char, vector<int>> um;
        for (int i = 0; i < n; i++) {
            um[s[i]].emplace_back(i);
        }
        int res = 0;
        for (auto&& [_, arr] : um) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(n);
            for (size_t i = 1; i + 1 < arr.size(); i++) {
                res += (arr[i + 1] - arr[i]) * (arr[i] - arr[i - 1]);
            }
        }
        return res;
    }
};
