// 1298_你能从盒子里获得的最大糖果数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        /** Status
        * 0. Lock, not own
        * 1. Unlock, not own 
        * 2. Lock, own
        * 3. Unlock, own
        */ 
        size_t n = status.size();
        queue<size_t> candidateBoxes;
        for (size_t initialBox : initialBoxes) {
            status[initialBox] += 2;
            if (status[initialBox] == 3) {
                candidateBoxes.push(initialBox);
            }
        }
        int sum = 0;
        while (!candidateBoxes.empty()) {
            size_t currBox = candidateBoxes.front();
            candidateBoxes.pop();
            sum += candies[currBox];
            for (size_t key : keys[currBox]) {
                if (status[key] & 1) {
                    continue;
                }
                status[key] += 1;
                if (status[key] == 3) {
                    candidateBoxes.push(key);
                }
            }
            for (size_t containedBox : containedBoxes[currBox]) {
                status[containedBox] += 2;
                if (status[containedBox] == 3) {
                    candidateBoxes.push(containedBox);
                }
            }
        }
        return sum;
    }
};
