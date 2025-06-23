// 2138_���ַ������Ϊ���ɳ���Ϊk����.cpp
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
