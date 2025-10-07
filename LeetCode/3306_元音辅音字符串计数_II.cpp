// 3306_ÔªÒô¸¨Òô×Ö·û´®¼ÆÊý_II.cpp
#include "stdafx.h"
ustd

class Solution {
    long long countOfSubstringsGE(string word, int k) {
        array<int, 128> count = { 0 };
        auto satisfy = [&]() {
            return count['a'] > 0 && count['e'] > 0 && count['i'] > 0 && count['o'] > 0 && count['u'] > 0;
        };
        auto sum = [&]() {
            return count['a'] + count['e'] + count['i'] + count['o'] + count['u'];
        };
        int i = 0, j = 0, n = static_cast<int>(word.size());
        long long result = 0;
        while (j < n) {  // [i, j)
            while (j < n && !satisfy()) {
                count[word[j++]]++;
            }
            while (j < n && j - i - sum() < k) {
                count[word[j++]]++;
            }
            if (satisfy() && j - i - sum() >= k) {
                result += static_cast<long long>(n - j + 1);
            }
            count[word[i++]]--;
        }
        while (i < n) {
            if (satisfy() && j - i - sum() >= k) {
                result += static_cast<long long>(n - j + 1);
            }
            count[word[i++]]--;
        }
        return result;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return countOfSubstringsGE(word, k) - countOfSubstringsGE(word, k + 1);
    }
};
