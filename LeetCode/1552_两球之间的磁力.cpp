// 1552_两球之间的磁力.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = *position.rbegin();
        auto check = [&](int force) {
            int cnt = 1;
            size_t i = 0, j = 1;
            while (j < position.size()) {
                if (position[j] - position[i] >= force) {
                    cnt++;
                    i = j;
                    j++;
                }
                else {
                    j++;
                }
            }
            return cnt >= m;
            };
        while (left < right) {  // [left, right)
            int mid = (left + right) / 2;
            if (check(mid)) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left - 1;
    }
};
