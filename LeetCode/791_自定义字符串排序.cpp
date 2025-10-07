// 791_×Ô¶¨Òå×Ö·û´®ÅÅÐò.cpp
#include "stdafx.h"
ustd

#define INDEX(c) static_cast<size_t>(c) - 'a'
#define CHAR(i) static_cast<char>(i) + 'a'

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26, 0);
        for (auto c : s) {
            cnt[INDEX(c)]++;
        }
        string result;
        for (auto c : order) {
            while (cnt[INDEX(c)] > 0) {
                result += c;
                cnt[INDEX(c)]--;
            }
        }
        for (size_t i = 0; i < cnt.size(); i++) {
            while (cnt[i] > 0) {
                result += CHAR(i);
                cnt[i]--;
            }
        }
        return result;
    }
};
