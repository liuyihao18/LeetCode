// 2255_ͳ���Ǹ����ַ���ǰ׺���ַ�����Ŀ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        string_view sv(s);
        int result = 0;
        for (const string& word : words) {
            if (word.size() <= sv.size() && word == sv.substr(0, word.size())) {
                result++;
            }
        }
        return result;
    }
};
