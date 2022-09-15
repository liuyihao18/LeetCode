// 672_µÆÅÝ¿ª¹Ø_¢ò.cpp
#include "custom.h"
ustd

class Solution {
public:
    int flipLights(int n, int presses) {
        return presses == 0 ? 1 :
            n == 1 ? 2 :
            n == 2 ? (presses == 1 ? 3 : 4) :
            (presses == 1 ? 4 : presses == 2 ? 7 : 8);
    }
};
