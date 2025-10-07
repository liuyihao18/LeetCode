// 710_黑名单中的随机数.cpp
#include "stdafx.h"
#include <random>
ustd

class Solution {
    mt19937 gen{ random_device{}() };
    int n;
    bool black;
    vector<int>& blacklist;
    vector<int> whitelist;
public:
    Solution(int n, vector<int>& blacklist) :n(n), blacklist(blacklist) {
        sort(blacklist.begin(), blacklist.end());
        if (n > 2 * blacklist.size()) {
            black = true;
        }
        else {
            size_t j = 0;
            for (int i = 0; i < n; i++) {
                if (j < blacklist.size() && i == blacklist[j]) {
                    j++;
                }
                else {
                    whitelist.push_back(i);
                }
            }
            black = false;
        }

    }

    int pick() {
        int r = 0;
        if (black) {
            uniform_int_distribution dis(0, n - 1);
            r = dis(gen);
            while (find(blacklist.begin(), blacklist.end(), r) != blacklist.end()) {
                r = dis(gen);
            }
        }
        else {
            uniform_int_distribution dis(0, static_cast<int>(whitelist.size()) - 1);
            int i = dis(gen);
            r = whitelist[i];
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
