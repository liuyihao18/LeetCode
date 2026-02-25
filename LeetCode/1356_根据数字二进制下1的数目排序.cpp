// 1356_根据数字二进制下1的数目排序.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        const auto bitCount{
            [](int num) {
                int cnt{0};
                while (num) {
                    cnt += num & 1;
                    num >>= 1;
                }
                return cnt;
            }
        };
        ranges::sort(arr,
            [&bitCount](int a, int b) {
                const int cntA = bitCount(a);
                const int cntB = bitCount(b);
                return cntA < cntB || (cntA == cntB && a < b);
            });
        return arr;
    }
};
