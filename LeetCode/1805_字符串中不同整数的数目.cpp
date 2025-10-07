// 1805_字符串中不同整数的数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int numDifferentIntegers(string word) {
        for (auto& c : word) {
            if (!isdigit(c)) {
                c = ' ';
            }
        }
        istringstream is(word);
        set<string> s;
        string num;
        while (is >> num) {
            while (num.size() > 1 && *num.begin() == '0') {
                num.erase(num.begin());
            }
            if (num.size() > 0) {
                s.insert(num);
            }
        }
        return static_cast<int>(s.size());
    }
};
