// 873_最长的斐波那契子序列的长度.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen = 0;
        for (size_t i = 0; i + 2 < arr.size(); i++) {
            for (size_t j = i + 1; j + 1 < arr.size(); j++) {
                int a = arr[i];
                int b = arr[j];
                int len = 2;
                while (true) {
                    int expected = a + b;
                    auto iter = lower_bound(arr.begin(), arr.end(), expected);
                    if (iter != arr.end() && *iter == expected) {
                        a = b;
                        b = expected;
                        len++;
                        continue;
                    }
                    else {
                        break;
                    }
                }
                if (len >= 3) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};
