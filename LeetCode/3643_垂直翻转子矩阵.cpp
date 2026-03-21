// 3643_´¹Ö±·­×ª×Ó¾ØÕó.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, const int x, const int y, const int k) {
        for (int i = 0; 2 * i < k; i++)
        {
			for (int j = 0; j < k; j++)
			{
                swap(grid[x + i][y + j], grid[x + k - i - 1][y + j]);
			}    
        }
        return grid;
    }
};
