// 1138_×ÖÄ¸°åÉÏµÄÂ·¾¶.cpp
#include "custom.h"
ustd

class Solution {
    pair<int, int> getPos(char c) {
        return { (c - 'a') / 5, (c - 'a') % 5 };
    }
public:
    string alphabetBoardPath(string target) {
        string result;
        constexpr pair<int, int> z = { 5,0 };
        pair<int, int> curr = { 0,0 };
        for (auto c : target) {
            pair<int, int> t = getPos(c);
            if (curr == z) {
                for (int i = 0; i < t.first - curr.first; i++) {
                    result += 'D';
                }
                for (int i = 0; i < curr.first - t.first; i++) {
                    result += 'U';
                }
                for (int i = 0; i < t.second - curr.second; i++) {
                    result += 'R';
                }
                for (int i = 0; i < curr.second - t.second; i++) {
                    result += 'L';
                }
            }
            else {
                for (int i = 0; i < t.second - curr.second; i++) {
                    result += 'R';
                }
                for (int i = 0; i < curr.second - t.second; i++) {
                    result += 'L';
                }
                for (int i = 0; i < t.first - curr.first; i++) {
                    result += 'D';
                }
                for (int i = 0; i < curr.first - t.first; i++) {
                    result += 'U';
                }
            }
            result += '!';
            curr = t;
        }
        return result;
    }
};
