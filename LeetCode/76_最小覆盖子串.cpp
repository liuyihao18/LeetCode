// 76_×îÐ¡¸²¸Ç×Ó´®.cpp
#include "stdafx.h"
ustd

class Solution {
    bool greater(const array<int, 128>& cnt_s, const array<int, 128>& cnt_t) {
        for (size_t i = 0; i < 128; i++) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        array<int, 128> cnt_s = {};
        array<int, 128> cnt_t = {};
        for (auto c : t) {
            cnt_t[c]++;
        }
        string result;
        size_t minLength = s.size() + 1, i = 0, j = 0;
        while (j < s.size()) {
            cnt_s[s[j++]]++;
            if (greater(cnt_s, cnt_t)) {
                while (i < j && greater(cnt_s, cnt_t)) {
                    cnt_s[s[i++]]--;
                }
                if (j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    result = s.substr(i - 1, j - i + 1);
                }
            }
        }
        return result;
    }
};
