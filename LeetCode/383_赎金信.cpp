// 383_Êê½ðÐÅ.cpp
#include "custom.h"
ustd

constexpr size_t INDEX(char c) {
    return static_cast<size_t>(c) - 'a';
}

class Solution {
public:
    bool canConstruct(const string& ransomNote, const string& magazine) {
        vector<int> counts(26, 0);
        for (auto c : magazine) {
            counts[INDEX(c)]++;
        }
        for (auto c : ransomNote) {
            counts[INDEX(c)]--;
        }
        for (auto count : counts) {
            if (count < 0) {
                return false;
            }
        }
        return true;
    }
};
