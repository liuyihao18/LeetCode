// 768_最多能完成排序的块_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> cnt;
        int result = 0;
        for (size_t i = 0; i < sorted.size(); i++) {
            int x = arr[i], y = sorted[i];
            if (++cnt[x] == 0) cnt.erase(x);
            if (--cnt[y] == 0) cnt.erase(y);
            if (cnt.size() == 0) result++;
        }
        return result;
    }
};
