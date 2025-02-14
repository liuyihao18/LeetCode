// 3_无重复字符的最长子串.cpp
#include "custom.h"
ustd

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128, 0);
        int i = 0, j = 0;
        int length = 0;
        while (j < s.size()) {
            if (cnt[s[j]] >= 1) {
                while (i < j) {
                    cnt[s[i]]--;
                    if (s[i++] == s[j]) {
                        break;
                    }
                }
            }
            else {
                cnt[s[j++]]++;
                length = max(length, j - i);
            }
        }
        return length;
    }
};
