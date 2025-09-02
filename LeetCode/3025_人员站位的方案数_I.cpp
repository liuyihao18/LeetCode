#include "custom.h"
ustd

class Solution {
    // 点在包围盒中
    bool isInRect(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
        return A[0] <= C[0] && C[0] <= B[0] && // x轴投影
            B[1] <= C[1] && C[1] <= A[1]; // y轴投影
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        size_t n = points.size();
        int result = 0;
        for (size_t i = 0; i < n; i++) {
            vector<int> candidates;
            for (size_t j = 0; j < n; j++) {
                if (j != i) {
                    const vector<int>& A = points[i];
                    const vector<int>& B = points[j];
                    if (A[0] <= B[0] && B[1] <= A[1]) {
                        candidates.push_back(j);
                    }
                }
            }
            size_t nn = candidates.size();
            for (size_t j = 0; j < nn; j++) {
                const vector<int>& A = points[i];
                const vector<int>& B = points[candidates[j]];
                bool hasPointInRect = false;
                for (size_t k = 0; k < nn; k++) {
                    if (k != j) {
                        const vector<int>& C = points[candidates[k]];
                        if (isInRect(A, B, C)) {
                            hasPointInRect = true;
                            break;
                        }
                    }
                }
                result += hasPointInRect == false;
            }
        }
        return result;
    }
};
