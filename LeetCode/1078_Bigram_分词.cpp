// 1078_Bigram_·Ö´Ê.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream is(text);
        string temp;
        vector<string> result;
        int state = 0;
        while (is >> temp) {
            switch (state) {
            case 0:
                if (temp == first) {
                    state = 1;
                }
                break;
            case 1:
                if (temp == second) {
                    state = 2;
                }
                else if (temp == first) {
                    state = 1;
                }
                else {
                    state = 0;
                }
                break;
            case 2:
                result.push_back(temp);
                if (second == first && temp == second) {
                    state = 2;
                }
                else if (temp == first) {
                    state = 1;
                }
                else {
                    state = 0;
                }
                break;
            default:
                break;
            }
        }
        return result;
    }
};
