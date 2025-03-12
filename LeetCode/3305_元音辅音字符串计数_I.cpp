// 3305_ÔªÒô¸¨Òô×Ö·û´®¼ÆÊý_I.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        size_t n = word.size();
        unordered_map<char, int> um;
        auto satisfy = [&]() {
            return um['a'] > 0 && um['e'] > 0 && um['i'] > 0 && um['o'] > 0 && um['u'] > 0;
        };
        auto sum = [&]() {
            return um['a'] + um['e'] + um['i'] + um['o'] + um['u'];
        };
        int result = 0;
        for (size_t i = 0; i < n; i++) {
            um.clear();
            for (size_t j = i; j < n; j++) {
                um[word[j]]++;
                if (!satisfy()) {
                    continue;
                }
                size_t s = sum();
                if (s + k == j - i + 1) {
                    result++;
                }
                else if (s + k < j - i + 1) {
                    break;
                }
            }
        }
        return result;
    }
};
