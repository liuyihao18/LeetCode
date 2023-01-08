// 2185_ͳ�ư�������ǰ׺���ַ���.cpp
#include "custom.h"
ustd

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        for (auto&& word : words) {
            if (word.size() < pref.size()) {
                continue;
            }
            if (word.substr(0, pref.size()) == pref) {
                result++;
            }
        }
        return result;
    }
};
