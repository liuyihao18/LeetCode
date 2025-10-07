// 1405_×î³¤¿ìÀÖ×Ö·û´®.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result;
        char ll = 0;
        char l = 0;
        while (a > 0 || b > 0 || c > 0) {
            int* max = nullptr;
            char curr = 0;
            if (a >= b && a > c) {
                max = &a;
                curr = 'a';
            }
            else if (b >= a && b > c) {
                max = &b;
                curr = 'b';
            }
            else {
                max = &c;
                curr = 'c';
            }
            if (curr == ll && curr == l) {
                if (max == &a) {
                    if (b >= c && b > 0) {
                        max = &b;
                        curr = 'b';
                    }
                    else if(c >= b && c > 0) {
                        max = &c;
                        curr = 'c';
                    }
                    else {
                        break;
                    }
                }
                else if (max == &b) {
                    if (a >= c && a > 0) {
                        max = &a;
                        curr = 'a';
                    }
                    else if (c >= a && c > 0) {
                        max = &c;
                        curr = 'c';
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (a >= b && a > 0) {
                        max = &a;
                        curr = 'a';
                    }
                    else if (b >= a && b > 0) {
                        max = &b;
                        curr = 'b';
                    }
                    else {
                        break;
                    }
                }
            }
            (*max)--;
            result += curr;
            ll = l;
            l = curr;
        }
        return result;
    }
};
