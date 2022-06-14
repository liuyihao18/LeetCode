// 498_¶Ô½ÇÏß±éÀú.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int m = static_cast<int>(mat.size()), n = static_cast<int>(mat.front().size());
        bool rightUp = true;
        int i = 0, j = 0;
        while (true) {
            result.push_back(mat[i][j]);
            if (rightUp) {
                i--;
                j++;
            }
            else {
                i++;
                j--;
            }
            if (j >= n) {
                j--;
                i += 2;
                rightUp = !rightUp;
            }
            else if (i >= m) {
                i--;
                j += 2;
                rightUp = !rightUp;
            }
            else if (j < 0) {
                j++;
                rightUp = !rightUp;
            }
            else if (i < 0) {
                i++;
                rightUp = !rightUp;
            }
            if (i + j + 2 > m + n) {
                break;
            }
        }
        return result;
    }
};
