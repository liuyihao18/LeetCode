// 717_1比特与2比特字符.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int state = 0;
        bool last = false;
        for (auto bit : bits) {
            switch (state) {
            case 0:
                if (bit) {
                    state = 1;
                }
                else {
                    last = true;
                }
                break;
            case 1:
                state = 0;
                last = false;
                break;
            default:
                break;
            }
        }
        return last;
    }
};
