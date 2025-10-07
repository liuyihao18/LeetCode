// 699_µôÂäµÄ·½¿é.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Square {
        int left;
        int right;
        int height;
    };
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<Square> squares;
        vector<int> results;
        int result = 0;
        for (size_t i = 0; i < positions.size(); i++) {
            int left = positions[i].front();
            int right = left + positions[i].back();
            int height = right - left;
            int base = 0;
            for (size_t j = 0; j < squares.size(); j++) {
                int overlapping = min(squares[j].right, right) - max(squares[j].left, left);
                if (overlapping > 0) {
                    base = max(base, squares[j].height);
                }
            }
            height = base + height;
            squares.push_back({ left,right,height });
            result = max(result, height);
            results.push_back(result);
        }
        return results;
    }
};
