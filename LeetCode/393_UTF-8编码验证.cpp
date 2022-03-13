// 393_UTF-8±‡¬Î—È÷§.cpp
#include "custom.h"
ustd

#define ONE(B)                 (~B & 0x80)
#define TWO(B)   (B & 0xC0) && (~B & 0x20)
#define THREE(B) (B & 0xE0) && (~B & 0x10)
#define FOUR(B)  (B & 0xF0) && (~B & 0x08)
#define BYTE(B)  (B & 0x80) && (~B & 0x40)

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int state = 1;
        for (auto d : data) {
            switch (state) {
            case 0:
                break;
            case 1:
                if (ONE(d)) state = 1;
                else if (TWO(d)) state = 2;
                else if (THREE(d)) state = 3;
                else if (FOUR(d)) state = 4;
                else return false;
                break;
            case 2:
                if (BYTE(d)) state = 1;
                else return false;
                break;
            case 3:
                if (BYTE(d)) state = 2;
                else return false;
                break;
            case 4:
                if (BYTE(d)) state = 3;
                else return false;
                break;
            default:
                break;
            }
        }
        if (state == 1) return true;
        else return false;
    }
};
