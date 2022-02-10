// 1447_最简分数.cpp
#include "custom.h"
ustd

class Solution {
    int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            if (r == 0) {
                break;
            }
            a = b;
            b = r;
        }
        return b;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) { // 分母
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) == 1) {
                    result.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return result;
    }
};
