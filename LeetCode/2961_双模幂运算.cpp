// 2961_Ë«Ä£ÃÝÔËËã.cpp
#include "custom.h"
ustd

class Solution {
    int powMod(int a, int n, int m) {
        if (n == 0) {
            return 1;
        }
        int x = powMod(a, n / 2, m) % m;
        if (n & 1) {
            return ((x * x) % m * (a % m)) % m;
        }
        else {
            return (x * x) % m;
        }
    }
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> indices;
        for (size_t i = 0; i < variables.size(); i++){
            const auto& variable = variables[i];
            auto a = variable[0];
            auto b = variable[1];
            auto c = variable[2];
            auto m = variable[3];
            auto result = powMod(a, b, 10);
            result = powMod(result, c, m);
            if (result == target) {
                indices.push_back(static_cast<int>(i));
            }
        }
        return indices;
    }
};
