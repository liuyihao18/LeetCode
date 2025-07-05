// 2138_将字符串拆分为若干长度为k的组.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> results;
        string temp;
        for (char c : s) {
            temp += c;
            if (temp.size() == k) {
                results.push_back(std::move(temp));
                temp.clear();
            }
        }
        while (temp.size() > 0 && temp.size() < k) temp += fill;
        if (temp.size() > 0) results.push_back(std::move(temp));
        return results;
    }
};
