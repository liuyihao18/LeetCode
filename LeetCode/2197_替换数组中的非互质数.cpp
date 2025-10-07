// 2197_替换数组中的非互质数.cpp
#include "stdafx.h"
ustd

class Solution {
    int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> result;
        auto my_push_back = [&](int a) {
            while (!result.empty()) {
                int c = result.back();
                int g = gcd(a, c);
                if (g == 1) {
                    break;
                }
                else {
                    result.pop_back();
                    a = (1LL * a * c) / g;
                }
            }
            result.push_back(a);
            };
        int a = nums[0];
        for (size_t i = 1; i < n; i++) {
            int b = nums[i];
            int g = gcd(a, b);
            if (g == 1) {
                my_push_back(a);
                a = b;
            }
            else {
                a = (1LL * a * b) / g;
            }
        }
        my_push_back(a);
        return result;
    }
};
