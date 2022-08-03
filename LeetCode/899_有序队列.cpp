// 899_�������.cpp
#include "custom.h"
ustd

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            s += s;
            // String View ���� substr �����������
            string_view sv(s), result(s);
            for (size_t i = 0, n = s.size() / 2; i < n; i++) {
                result = min(result, sv.substr(i, n));
            }
            return string(result);
        }
        else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};
