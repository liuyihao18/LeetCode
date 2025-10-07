// 3443_K次修改后的最大曼哈顿距离.cpp
#include "stdafx.h"
ustd

class Solution {
    int _maxDistance(const vector<int>& counts, int k) {
        int count0 = min(counts[0], counts[1]);
        int count1 = max(counts[0], counts[1]);
        int count2 = min(counts[2], counts[3]);
        int count3 = max(counts[2], counts[3]);
        if (count0 <= k) {
            count1 += count0;
            k -= count0;
            count0 = 0;
        }
        else {
            count1 += k;
            count0 -= k;
            k = 0;
        }
        if (count2 <= k) {
            count3 += count2;
            k -= count2;
            count2 = 0;
        }
        else {
            count3 += k;
            count2 -= k;
            k = 0;
        }
        return count1 - count0 + count3 - count2;
    }
public:
    int maxDistance(string s, int k) {
        int distance = 0;
        vector<int> counts(4, 0);
        for (auto c : s) {
            switch (c) {
            case 'N':
                counts[0]++;
                break;
            case 'S':
                counts[1]++;
                break;
            case 'E':
                counts[2]++;
                break;
            case 'W':
                counts[3]++;
                break;
            default:
                break;
            }
            distance = max(distance, _maxDistance(counts, k));
        }
        return distance;
    }
};
