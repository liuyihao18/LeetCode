// 782_��Ϊ����.cpp
#include "custom.h"
ustd

#ifdef GCC
class Solution {
public:
    int getMoves(int mask, int count, int n) {
        int ones = __builtin_popcount(mask);
        if (n & 1) {
            /* ��� n Ϊ��������ÿһ���� 1 �� 0 ����Ŀ���Ϊ 1�������������н��� */
            if (abs(n - 2 * ones) != 1 || abs(n - 2 * count) != 1) {
                return -1;
            }
            if (ones == (n >> 1)) {
                /* ż��λ��Ϊ 1 ����С�������� */
                return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            }
            else {
                /* ����λ��Ϊ 1 ����С�������� */
                return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
            }
        }
        else {
            /* ��� n Ϊż������ÿһ���� 1 �� 0 ����Ŀ��ȣ������������н��� */
            if (ones != (n >> 1) || count != (n >> 1)) {
                return -1;
            }
            /* ż��λ��Ϊ 1 ����С�������� */
            int count0 = n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            /* ����λ��Ϊ 1 ����С�������� */
            int count1 = n / 2 - __builtin_popcount(mask & 0x55555555);
            return min(count0, count1);
        }
    }

    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        int rowMask = 0, colMask = 0;

        /* ������̵ĵ�һ�����һ�� */
        for (int i = 0; i < n; i++) {
            rowMask |= (board[0][i] << i);
            colMask |= (board[i][0] << i);
        }
        int reverseRowMask = ((1 << n) - 1) ^ rowMask;
        int reverseColMask = ((1 << n) - 1) ^ colMask;
        int rowCnt = 0, colCnt = 0;
        for (int i = 0; i < n; i++) {
            int currRowMask = 0;
            int currColMask = 0;
            for (int j = 0; j < n; j++) {
                currRowMask |= (board[i][j] << j);
                currColMask |= (board[j][i] << j);
            }
            /* ���ÿһ�е�״̬�Ƿ�Ϸ� */
            if (currRowMask != rowMask && currRowMask != reverseRowMask) {
                return -1;
            }
            else if (currRowMask == rowMask) {
                /* ��¼���һ����ͬ������ */
                rowCnt++;
            }
            /* ���ÿһ�е�״̬�Ƿ�Ϸ� */
            if (currColMask != colMask && currColMask != reverseColMask) {
                return -1;
            }
            else if (currColMask == colMask) {
                /* ��¼���һ����ͬ������ */
                colCnt++;
            }
        }
        int rowMoves = getMoves(rowMask, rowCnt, n);
        int colMoves = getMoves(colMask, colCnt, n);
        return (rowMoves == -1 || colMoves == -1) ? -1 : (rowMoves + colMoves);
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/transform-to-chessboard/solution/bian-wei-qi-pan-by-leetcode-solution-39dd/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
#endif
