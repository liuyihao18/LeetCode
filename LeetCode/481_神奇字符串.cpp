// 481_ÉñÆæ×Ö·û´®.cpp
#include "custom.h"
ustd

class Solution {
public:
    int magicalString(int n) {
        if (n < 4) {
            return 1;
        }
        vector<char> s(n, 0);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;
        size_t i = 2, j = 3;
        int result = 1;
        while (j < n) {
            int size = s[i];
            int num = 3 - s[j - 1];
            while (size > 0 && j < n) {
                s[j] = num;
                if (num == 1) {
                    result++;
                }
                j++;
                size--;
            }
            i++;
        }
        return result;
    }
};
