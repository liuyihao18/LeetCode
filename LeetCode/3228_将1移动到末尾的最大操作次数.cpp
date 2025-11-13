// 3228_将1移动到末尾的最大操作次数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxOperations(string s) {
        vector<int> index;
        int n = static_cast<int>(s.size());
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                index.push_back(i);
            }
        }
        int result = 0;
        int m = static_cast<int>(index.size());
        for (int i = 0; i + 1 < m; i++) {
            if (index[i] + 1 < index[i + 1ULL]) {
                result += i + 1;
            }
        }
        if (m > 0 && index.back() < n - 1) {
            result += m;
        }
        return result;
    }
};
