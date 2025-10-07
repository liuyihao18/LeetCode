// ÃæÊÔÌâ_01_09_×Ö·û´®ÂÖ×ª.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        string_view sv1(s1), sv2(s2);
        for (size_t i = 0; i < s1.size(); i++) {
            if (sv1.substr(0, i) == sv2.substr(sv2.size() - i)
                && sv1.substr(i) == sv2.substr(0, sv2.size() - i)) {
                return true;
            }
        }
        return false;
        // return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
    }
};
