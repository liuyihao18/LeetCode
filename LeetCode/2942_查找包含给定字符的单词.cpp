// 2942_���Ұ��������ַ��ĵ���.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = static_cast<int>(words.size());
        vector<int> results;
        for (int i = 0; i < n; i++) {
            if (words[i].find(x) != string::npos) {
                results.push_back(i);
            }
        }
        return results;
    }
};
