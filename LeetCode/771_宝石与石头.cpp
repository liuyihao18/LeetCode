#include "custom.h"
ustd

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        auto check = [&](char stone) {
            for (auto jewel : jewels) {
                if (stone == jewel) {
                    return true;
                }
            }
            return false;
        };
        int result = 0;
        for (auto stone : stones) {
            if (check(stone)) {
                result++;
            }
        }
        return result;
    }
};
