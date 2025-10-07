// 781_森林中的兔子.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> m;
        for (auto answer : answers) {
            m[answer]++;
        }
        int rabbits = 0;
        for (const auto& [k, v] : m) {
            rabbits += ((v - 1) / (k + 1) + 1) * (k + 1);
        }
        return rabbits;
    }
};
