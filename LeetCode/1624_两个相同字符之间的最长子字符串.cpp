// 1624_两个相同字符之间的最长子字符串.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = static_cast<int>(s.size());
        vector<pair<int, int>> pos(26, { -1,-1 });
        for (int i = 0; i < n; i++) {
            if (pos[static_cast<size_t>(s[i] - 'a')].first == -1) {
                pos[static_cast<size_t>(s[i] - 'a')].first = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (pos[static_cast<size_t>(s[i] - 'a')].second == -1) {
                pos[static_cast<size_t>(s[i] - 'a')].second = i;
            }
        }
        vector<int> length;
        transform(pos.begin(), pos.end(), back_inserter(length), 
            [](const pair<int, int>& p) {
                return p.second - p.first - 1;
            });
        return *max_element(length.begin(), length.end());
    }
};
