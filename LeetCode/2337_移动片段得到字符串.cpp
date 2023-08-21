// 2337_ÒÆ¶¯Æ¬¶ÎµÃµ½×Ö·û´®.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool canChange(string start, string target) {
        string startLR, targetLR;
        copy_if(start.begin(), start.end(), back_inserter(startLR), [](char c) {
            return c != '_';
            }
        );
        copy_if(target.begin(), target.end(), back_inserter(targetLR), [](char c) {
            return c != '_';
            }
        );
        if (startLR != targetLR) {
            return false;
        }
        size_t n = start.size();
        vector<size_t> startLPos;
        vector<size_t> startRPos;
        vector<size_t> targetLPos;
        vector<size_t> targetRPos;
        for (size_t i = 0; i < n; i++) {
            if (start[i] == 'L') {
                startLPos.push_back(i);
            }else if (start[i] == 'R'){
                startRPos.push_back(i);
            }
            if (target[i] == 'L') {
                targetLPos.push_back(i);
            }
            else if (target[i] == 'R') {
                targetRPos.push_back(i);
            }
        }
        for (size_t i = 0; i < startLPos.size(); i++) {
            if (startLPos[i] < targetLPos[i]) {
                return false;
            }
        }
        for (size_t i = 0; i < startRPos.size(); i++) {
            if (startRPos[i] > targetRPos[i]) {
                return false;
            }
        }
        return true;
    }
};
