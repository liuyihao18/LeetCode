// 372_³¬¼¶´Î·½.cpp
#include "stdafx.h"
ustd

class Solution {
    const int MODULES = 1337;
    void devide2(vector<int>& b) {
        int sub = 0;
        for (auto iter = b.begin(); iter != b.end(); ) {
            *iter += sub * 10;
            sub = *iter % 2;
            *iter /= 2;
            if (iter == b.begin() && *iter == 0) {
                iter = b.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        if (b.back() & 1) {
            b.back() -= 1;
            if (b.size() == 1 && b.back() == 0) {
                b.clear();
            }
            return ((superPow(a, b) % MODULES) * (a % MODULES)) % MODULES;
        }
        else {
            devide2(b);
            int temp = superPow(a, b) % MODULES;
            return (temp * temp) % MODULES;
        }
    }
};
