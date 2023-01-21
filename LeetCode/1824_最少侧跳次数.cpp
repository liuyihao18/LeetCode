// 1824_���ٲ�������.cpp
#include "custom.h"
ustd

class Solution {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = static_cast<int>(obstacles.size()) - 1;
        vector<int> d = { 1, 0, 1 };
        for (int i = 1; i <= n; i++) {
            int minCnt = inf;
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    d[j] = inf;
                }
                else {
                    minCnt = min(minCnt, d[j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/minimum-sideway-jumps/solutions/2070379/zui-shao-ce-tiao-ci-shu-by-leetcode-solu-3y2g/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
