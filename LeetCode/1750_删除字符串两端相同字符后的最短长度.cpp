// 1750_ɾ���ַ���������ͬ�ַ������̳���.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minimumLength(string s) {
        size_t i = 0, j = s.size() - 1;
        while (true) {
            if (j - i < 1 || s[i] != s[j]) {
                break;
            }
            auto c = s[i];
            while (j - i + 1 > 0 && s[i] == c) {
                i++;
            }
            while (j - i + 1 > 0 && s[j] == c) {
                j--;
            }
        }
        return static_cast<int>(j - i + 1);
    }
};
