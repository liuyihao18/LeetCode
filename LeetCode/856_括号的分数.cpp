// 856_À¨ºÅµÄ·ÖÊý.cpp
#include "custom.h"
ustd

class Solution {
    int scoreOfParentheses(const string_view& s) {
        if (s.size() == 2) {
            return 1;
        }
        int cnt = 0;
        size_t i = 0;
        for (; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
            }
            else if (s[i] == ')') {
                cnt--;
            }
            if (cnt == 0) {
                break;
            }
        }
        if (i + 1 == s.size()) {
            return 2 * scoreOfParentheses(s.substr(1, s.size() - 2));
        }
        return scoreOfParentheses(s.substr(0, i + 1)) + scoreOfParentheses(s.substr(i + 1));
    }
public:
    int scoreOfParentheses(string s) {
        string_view sView(s);
        return scoreOfParentheses(sView);
    }
};
