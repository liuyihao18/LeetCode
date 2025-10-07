// 2810_π ’œº¸≈Ã.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string finalString(string s) {
        list<char> l;
        bool dir = true;
        for (auto c : s) {
            if (c == 'i') {
                dir = !dir;
            }
            else {
                if (dir) {
                    l.push_back(c);
                }
                else {
                    l.push_front(c);
                }
            }
        }
        string res;
        if (dir) {
            copy(l.begin(), l.end(), back_inserter(res));
        }
        else {
            copy(l.rbegin(), l.rend(), back_inserter(res));
        }
        return res;
    }
};
