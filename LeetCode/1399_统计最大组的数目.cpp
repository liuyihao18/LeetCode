// 1399_统计最大组的数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> counts;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            int digitSum = accumulate(s.begin(), s.end(), 0, [](int sum, char c) { return sum += c - '0'; });
            counts[digitSum]++;
        }
        int largest = 0, count = 0;
        for (const auto& [_, v] : counts) {
            if (v > largest) {
                largest = v;
                count = 1;
            }
            else if (v == largest) {
                count++;
            }
        }
        return count;
    }
};
