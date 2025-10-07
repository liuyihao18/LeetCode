// 784_字母大小写全排列.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<pair<string, size_t>> q;
        set<string> visited;
        string s1 = s, s2 = s;
        s1[0] = tolower(s1[0]);
        s2[0] = toupper(s2[0]);
        if (s1 != s2) {
            q.emplace(s1, 0);
            q.emplace(s2, 0);
        }
        else {
            q.emplace(s1, 0);
        }
        while (!q.empty()) {
            pair<string, size_t> curr = q.front();
            q.pop();
            visited.emplace(curr.first);
            size_t index = curr.second + 1;
            if (index >= s.size()) {
                continue;
            }
            string s1 = curr.first, s2 = curr.first;
            s1[index] = tolower(s1[index]);
            s2[index] = toupper(s2[index]);
            if (s1 != s2) {
                q.emplace(s1, index);
                q.emplace(s2, index);
            }
            else {
                q.emplace(s1, index);
            }
        }
        return vector<string>(visited.begin(), visited.end());
    }
};
