// 299_²ÂÊı×ÖÓÎÏ·.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string getHint(string secret, string guess) {
        size_t x = 0;
        size_t y = 0;
        vector<size_t> secret_count(10, 0);
        vector<size_t> guess_count(10, 0);
        for (size_t i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                x++;
            }
            else {
                secret_count[secret[i] - '0']++;
                guess_count[guess[i] - '0']++;
            }
        }
        for (size_t i = 0; i < secret_count.size(); i++) {
            y += min(secret_count[i], guess_count[i]);
        }
        return to_string(x) + 'A' + to_string(y) + 'B';
    }
};