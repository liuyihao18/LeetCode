// 2612_最少翻转操作数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        set<int> oddNumbers;
        set<int> evenNumbers;
        for (int i = 0; i < n; i += 2) {
            evenNumbers.insert(i);
        }
        for (int i = 1; i < n; i += 2) {
            oddNumbers.insert(i);
        }
        for (size_t i = 0; i < banned.size(); i++) {
            oddNumbers.erase(banned[i]);
            evenNumbers.erase(banned[i]);
        }
        queue<int> q;
        q.emplace(p);
        oddNumbers.erase(p);
        evenNumbers.erase(p);
        ans[p] = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            set<int>* numbers = nullptr;
            if ((k - curr) & 1) {
                numbers = &evenNumbers;
            }
            else {
                numbers = &oddNumbers;
            }
            {
                set<int>::iterator rightIter = numbers->upper_bound(curr + k - 1);
                set<int>::iterator leftIter = numbers->lower_bound(curr);
                if (leftIter != numbers->end()) {
                    for (; leftIter != rightIter; ) {
                        int i = *leftIter - curr;
                        int need = (k - (i + 1)) / 2;
                        int left = curr - need;
                        int right = curr + i + need;
                        if (left >= 0 && right < n) {
                            ans[*leftIter] = ans[curr] + 1;
                            q.emplace(*leftIter);
                            leftIter = numbers->erase(leftIter);
                        }
                        else {
                            ++leftIter;
                        }
                    }
                }
            }
            {
                set<int>::iterator rightIter = numbers->upper_bound(curr);
                set<int>::iterator leftIter = numbers->lower_bound(curr - k + 1);
                if (leftIter != numbers->end()) {
                    for (; leftIter != rightIter; ) {
                        int i = curr - *leftIter;
                        int need = (k - (i + 1)) / 2;
                        int left = curr - i - need;
                        int right = curr + need;
                        if (left >= 0 && right < n) {
                            ans[*leftIter] = ans[curr] + 1;
                            q.emplace(*leftIter);
                            leftIter = numbers->erase(leftIter);
                        }
                        else {
                            ++leftIter;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
