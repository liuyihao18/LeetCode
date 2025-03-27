// 2712_ʹ�����ַ���ȵ���С�ɱ�.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long minimumCost(string s) {
        size_t n = s.size();
        long long result = 0;
        for (size_t i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                result += min(i, n - i);
            }
        }
        return result;
    }
};
