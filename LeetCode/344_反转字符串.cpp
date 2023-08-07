// 344_·´×ª×Ö·û´®.cpp
#include "custom.h"
ustd

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (size_t i = 0; i * 2 < s.size(); i++) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};
