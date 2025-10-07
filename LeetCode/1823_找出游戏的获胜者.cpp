// 1823_找出游戏的获胜者.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        auto iter = s.begin();
        while (s.size() > 1) {
            for (int i = 1; i < k; i++) {
                iter++;
                if (iter == s.end()) {
                    iter = s.begin();
                }
            }
            iter = s.erase(iter);
            if (iter == s.end()) {
                iter = s.begin();
            }
        }
        return *s.begin();
    }
};
