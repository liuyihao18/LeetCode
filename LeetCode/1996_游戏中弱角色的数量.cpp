// 1996_游戏中弱角色的数量.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return (v1[0] == v2[0]) ? (v1[1] < v2[1]) : (v1[0] > v2[0]);
            });
        int maxDef = 0;
        int result = 0;
        for (const auto& p : properties) {
            if (p[1] < maxDef) {
                result++;
            }
            else {
                maxDef = p[1];
            }
        }
        return result;
    }
};
