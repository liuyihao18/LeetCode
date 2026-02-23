// 1461_检查一个字符串是否包含所有长度为K的二进制子串.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool hasAllCodes(const string& s, int k) {
        if (s.size() < k) return false;
        unordered_set<int> st;
        int num{ 0 };
        size_t i{ 0 };
        for (; i < k; i++) {
            num <<= 1;
            num |= s[i] - '0';
        }
        st.insert(num);
        int mask{ 1 << k };
        for (size_t n{ s.size() }; i < n; i++) {
            num <<= 1;
            num &= ~mask;
            num |= s[i] - '0';
            st.insert(num);
        }
        return st.size() == mask;
    }
};
