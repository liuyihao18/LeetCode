// 809_情感丰富的文字.cpp
#include "custom.h"
ustd

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int result = 0;
        for (const auto& word : words) {
            if (expand(word, s)) {
                result++;
            }
        }
        return result;
    }
public:
    bool expand(const string& s, const string& t) {
        size_t i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                return false;
            }
            char c = s[i];
            int cnt_s = 0;
            int cnt_t = 0;
            while (i < s.size() && s[i] == c) {
                i++;
                cnt_s++;
            }
            while (j < t.size() && t[j] == c) {
                j++;
                cnt_t++;
            }
            if (cnt_t < cnt_s) {
                return false;
            }
            if (cnt_t != cnt_s && cnt_t < 3) {
                return false;
            }
        }
        return i == s.size() && j == t.size();
    }
};
