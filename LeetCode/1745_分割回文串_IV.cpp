// 1745_·Ö¸î»ØÎÄ´®_IV.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool checkPartitioning(string s) {
        size_t n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        for (size_t i = n - 1; i != -1; i--) {
            for (size_t j = i + 1; j != n; j++) {
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        for (size_t i = 0; i < s.size(); i++) {
            for (size_t j = i + 1; j + 1 < s.size(); j++) {
                if (isPalindrome[0][i] && isPalindrome[i + 1][j] && isPalindrome[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
