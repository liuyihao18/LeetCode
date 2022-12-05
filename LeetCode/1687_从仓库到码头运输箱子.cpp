// 1687_从仓库到码头运输箱子.cpp
#include "custom.h"
ustd

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = static_cast<int>(boxes.size());
        vector<int> p(n + 1), w(n + 1), neg(n + 1);
        vector<long long> W(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = boxes[i - 1][0];
            w[i] = boxes[i - 1][1];
            if (i > 1) {
                neg[i] = neg[i - 1] + (p[i - 1] != p[i]);
            }
            W[i] = W[i - 1] + w[i];
        }

        deque<int> opt = { 0 };
        vector<int> f(n + 1), g(n + 1);

        for (int i = 1; i <= n; ++i) {
            while (i - opt.front() > maxBoxes || W[i] - W[opt.front()] > maxWeight) {
                opt.pop_front();
            }

            f[i] = g[opt.front()] + neg[i] + 2;

            if (i != n) {
                g[i] = f[i] - neg[i + 1];
                while (!opt.empty() && g[i] <= g[opt.back()]) {
                    opt.pop_back();
                }
                opt.push_back(i);
            }
        }

        return f[n];
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/delivering-boxes-from-storage-to-ports/solutions/2005717/cong-cang-ku-dao-ma-tou-yun-shu-xiang-zi-4uya/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
