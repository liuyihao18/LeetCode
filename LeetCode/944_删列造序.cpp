// 944_…æ¡–‘Ï–Ú.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        size_t n = strs.front().size();
        int result = 0;
        for (size_t i = 0; i < n; i++) {
            char last_c = CHAR_MIN;
            for (const auto& str : strs) {
                if (str[i] < last_c) {
                    result++;
                    break;
                }
                last_c = str[i];
            }
        }
        return result;
    }
};
