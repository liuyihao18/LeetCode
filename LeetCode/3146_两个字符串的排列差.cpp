// 3146_两个字符串的排列差.cpp
#include "custom.h"
ustd

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
        }
        int sum = 0;
        for (int j = 0; j < t.size(); j++) {
            sum += abs(m[t[j]] - j);
        }
        return sum;
    }
};
