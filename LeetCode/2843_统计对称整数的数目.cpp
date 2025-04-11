// 2843_统计对称整数的数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            if (s.size() & 1) {
                continue;
            }
            string l = s.substr(0, s.size() / 2);
            string r = s.substr(s.size() / 2);
            if (accumulate(l.begin(), l.end(), 0) == accumulate(r.begin(), r.end(), 0)) {
                result++;
            }
        }
        return result;
    }
};
