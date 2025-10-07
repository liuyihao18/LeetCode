// 2682_找出转圈游戏输家.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n, false);
        int i = 0, epoch = 1;
        while (true) {
            if (visited[i]) {
                break;
            }
            else {
                visited[i] = true;
            }
            i = (i + epoch * k) % n;
            epoch++;
        }
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                answer.push_back(i + 1);
            }
        }
        return answer;
    }
};
