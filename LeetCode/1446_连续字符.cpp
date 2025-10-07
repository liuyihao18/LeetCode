// 1446_Á¬Ðø×Ö·û.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxPower(const string& s) {
        if (s.size() == 0) {
            return 0;
        }
        int max_length = 0;
        int length = 0;
        string::value_type last = -1;
        for (auto c : s) {
            if (c == last) {
                length++;
            }
            else {
                max_length = max(max_length, length);
                last = c;
                length = 1;
            }
        }
        max_length = max(max_length, length);
        return max_length;
    }
};