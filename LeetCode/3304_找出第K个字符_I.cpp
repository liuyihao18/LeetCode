// 3304_ÕÒ³öµÚK¸ö×Ö·û_I.cpp
#include "custom.h"
ustd

class Solution {
    string nextString(const string& s) {
        string res = s;
        for (char& c : res) {
            c++;
            if (c > 'z') {
                c = 'a';
			}
        }
        return res;
    }

public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            s += nextString(s);
        }
        return s[static_cast<size_t>(k - 1)];
    }
};
