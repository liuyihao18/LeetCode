// 3541_找到频率最高的元音和辅音.cpp
#include "custom.h"
ustd

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxFreqSum(string s) {
        int countVowels[128] = { 0 };
        int countConsonant[128] = { 0 };
        for (char c : s) {
            if (isVowel(c)) {
                countVowels[c]++;
            }
            else {
                countConsonant[c]++;
            }
        }
        return *max_element(begin(countVowels), end(countVowels)) + *max_element(begin(countConsonant), end(countConsonant));
    }
};
