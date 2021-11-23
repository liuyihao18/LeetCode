// 859_Ç×ÃÜ×Ö·û´®.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool buddyStrings(const string& s, const string& goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        map<string::value_type, size_t> counts;
        size_t ci{ 0 };
        bool zero = false;
        size_t last = -1;
        for (size_t i = 0; i < s.size(); i++) {
            if (++counts[s[i]] >= 2) {
                zero = true;
            }
            if (s[i] != goal[i]) {
                ci++;
                if (ci > 2) {
                    return false;
                }
                if (last == -1) {
                    last = i;
                }
                else {
                    if (s[i] != goal[last] || goal[i] != s[last]) {
                        return false;
                    }
                }
            }
        }
        if (ci == 0 && zero) {
            return true;
        }
        if (ci != 2) {
            return false;
        }
        return true;
    }
};
