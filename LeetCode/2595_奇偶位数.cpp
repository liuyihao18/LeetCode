// 2595_ÆæÅ¼Î»Êý.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        for (size_t i = 0; i < 32; i++) {
            if (n >> i & 1) {
                i & 1 ? odd++ : even++;
            }
        }
        return { even, odd };
    }
};
