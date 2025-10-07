// 779_µÚK¸öÓï·¨·ûºÅ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int kthGrammar(int n, int k) {
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (result == 0) {
                if ((k - 1) >> (n - 1 - i) & 1) {
                    result = 1;
                }
                else {
                    result = 0;
                }
            }
            else {
                if ((k - 1) >> (n - 1 - i) & 1) {
                    result = 0;
                }
                else {
                    result = 1;
                }
            }
        }
        return result;
    }
};
