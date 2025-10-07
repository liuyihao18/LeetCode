// 1629_按键持续时间最长的键.cpp
#include "stdafx.h"
ustd

constexpr size_t INDEX(char c) {
    return static_cast<size_t>(c) - 'a';
}

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> keyTime(26, 0);
        size_t i = 0;
        keyTime[INDEX(keysPressed[i])] = releaseTimes[i];
        i++;
        for (; i < keysPressed.size(); i++) {
            keyTime[INDEX(keysPressed[i])] = 
                max(keyTime[INDEX(keysPressed[i])], releaseTimes[i] - releaseTimes[i - 1]);
        }
        auto iter = max_element(keyTime.rbegin(), keyTime.rend());
        return static_cast<char>(distance(iter, --keyTime.rend())) + 'a';
    }
};
