// 6_Z×ÖÐÎ±ä»».cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> results(numRows);
        size_t pos = 0;
        while (pos < s.size()) {
            for (int i = 0; i < numRows; i++) {
                if (pos >= s.size()) {
                    break;
                }
                results[i].push_back(s[pos++]);
            }
            for (int i = numRows - 2; i > 0; i--) {
                if (pos >= s.size()) {
                    break;
                }
                results[i].push_back(s[pos++]);
            }
        }
        return accumulate(results.begin(), results.end(), string());
    }
};
