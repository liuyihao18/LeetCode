// 2347_最好的扑克手牌.cpp
#include "custom.h"
ustd

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (all_of(suits.begin(), suits.end(), [&](char c) { return c == suits.front(); })) {
            return "Flush";
        }
        map<int, int> cnt;
        for (auto rank : ranks) {
            cnt[rank]++;
        }
        for (const auto& [_, c] : cnt) {
            if (c >= 3) {
                return "Three of a Kind";
            }
        }
        for (const auto& [_, c] : cnt) {
            if (c == 2) {
                return "Pair";
            }
        }
        return "High Card";
    }
};
