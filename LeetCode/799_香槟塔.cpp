// 799_ÏãéÄËþ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = { static_cast<double>(poured) };
        for (size_t i = 1; i <= query_row; i++) {
            vector<double> nextRow(i + 1, 0.0);
            for (size_t j = 0; j < row.size(); j++) {
                double volume = row[j];
                if (volume > 1) {
                    nextRow[j] += (volume - 1) / 2;
                    nextRow[j + 1] += (volume - 1) / 2;
                }
            }
            row = std::move(nextRow);
        }
        return min(1.0, row[query_glass]);
    }
};
