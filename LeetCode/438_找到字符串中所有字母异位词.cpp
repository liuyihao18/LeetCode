// 438_找到字符串中所有字母异位词.cpp
#include "custom.h"
ustd

constexpr size_t INDEX(char c) {
    return static_cast<size_t>(c) - 'a';
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<size_t> counts_p(26, 0);
        for (auto c : p) {
            counts_p[INDEX(c)]++;
        }
        vector<size_t> counts_s(26, 0);
        for (size_t i = 0; i < min(s.size(), p.size()); i++) {
            counts_s[INDEX(s[i])]++;
        }
        vector<int> result;
        size_t i = 0;
        while (i + p.size() < s.size()) {
            if (counts_s == counts_p) {
                result.push_back(i);
            }
            counts_s[INDEX(s[i])]--;
            counts_s[INDEX(s[i + p.size()])]++;
            i++;
        }
        if (counts_s == counts_p) {
            result.push_back(static_cast<int>(i));
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        vector<size_t> counts_p(26, 0);
        for (auto c : p) {
            counts_p[INDEX(c)]++;
        }
        vector<size_t> counts_s(26, 0);
        for (size_t i = 0; i < p.size(); i++) {
            counts_s[INDEX(s[i])]++;
        }
        bool found = counts_s == counts_p;
        vector<int> result;
        if (found) {
            result.push_back(0);
        }
        for (size_t i = 1; i < s.size() - p.size() + 1; i++) {
            if (found) {
                if (s[i - 1] == s[i + p.size() - 1]) {
                    result.push_back(static_cast<int>(i));
                }
                else {
                    counts_s[INDEX(s[i - 1])]--;
                    counts_s[INDEX(s[i + p.size() - 1])]++;
                    found = false;
                }
            }
            else {
                counts_s[INDEX(s[i - 1])]--;
                counts_s[INDEX(s[i + p.size() - 1])]++;
                found = counts_s == counts_p;
                if (found) {
                    result.push_back(static_cast<int>(i));
                }
            }
        }
        return result;
    }
};
*/
