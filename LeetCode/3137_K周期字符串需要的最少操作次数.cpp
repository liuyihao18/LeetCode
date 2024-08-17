// 3137_K�����ַ�����Ҫ�����ٲ�������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> um;
        int cnt = 0;
        for (size_t i = 0; i < word.size(); i += k) {
            cnt = max(cnt, ++um[word.substr(i, k)]);
        }
        return static_cast<int>(word.size()) / k - cnt;
    }
};
