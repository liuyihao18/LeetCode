// 522_最长特殊序列_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        map<string, size_t> m;
        for (const auto& str : strs) {
            size_t max = static_cast<size_t>(1) << str.size();
            for (size_t s = 0; s < max; s++) {
                string temp;
                for (size_t i = 0; i < str.size(); i++) {
                    if ((static_cast<size_t>(1) << i) & s) {
                        temp += str[i];
                    }
                }
                m[temp]++;
            }
        }
        int result = -1;
        for (const auto& [key, val] : m) {
            if (val == 1) {
                result = max(result, static_cast<int>(key.size()));
            }
        }
        return result;
    }
};
