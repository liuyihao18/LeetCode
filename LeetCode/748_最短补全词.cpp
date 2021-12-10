// 748_×î¶Ì²¹È«´Ê.cpp
#include "custom.h"
ustd

class Solution {
public:
    string shortestCompletingWord(const string& licensePlate, vector<string>& words) {
        vector<size_t> count(26, 0);
        for (auto c : licensePlate) {
            if (!isblank(c) && !isdigit(c)) {
                count[static_cast<vector<size_t>::size_type>(tolower(c)) - 'a']++;
            }
        }
        size_t min_length = INT_MAX;
        string result;
        for (auto&& word : words) {
            vector<size_t> w_count(count);
            for (auto c : word) {
                w_count[static_cast<vector<size_t>::size_type>(tolower(c)) - 'a']
                    && w_count[static_cast<vector<size_t>::size_type>(tolower(c)) - 'a']--;
            }
            if (all_of(w_count.begin(), w_count.end(), [](size_t c) { return !c; })) {
                if (word.size() < min_length) {
                    result = word;
                    min_length = word.size();
                }
            }
        }
        return result;
    }
};
