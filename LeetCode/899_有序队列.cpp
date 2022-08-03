// 899_有序队列.cpp
#include "custom.h"
ustd

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            s += s;
            // String View 调用 substr 不会产生复制
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
