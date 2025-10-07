// 318_最大单词长度乘积.cpp
#include "stdafx.h"
ustd
#define HASH

class Solution {
public:
    int maxProduct(vector<string>& words) {
#ifdef HASH
        vector<size_t> hash_table;
        for (auto word : words) {
            size_t s = 0;
            for (auto c : word) {
                s |= (static_cast<size_t>(1) << (c - 'a'));
            }
            hash_table.push_back(s);
        }
#endif // HASH
        size_t max_length_product = 0;
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = i + 1; j < words.size(); j++) {
#ifdef HASH
                if ((hash_table[i] & hash_table[j]) == 0) {
#else
                if (words[i].find_first_of(words[j]) == string::npos) {
#endif // HASH
                    max_length_product = max(max_length_product, words[i].size() * words[j].size());
                }
            }
        }
        return static_cast<int>(max_length_product);
    }
};