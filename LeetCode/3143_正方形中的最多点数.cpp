// 3143_�������е�������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // С�ڴ�С�뾶�ĵ㶼�ǺϷ��ĵ�
        vector<int> min1(26, 1000000001);
        int min2 = 1000000001;
        for (size_t i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1], c = s[i] - 'a';
            // ĳ����ǩ�ĵ�İ뾶
            int d = max(abs(x), abs(y));
            // ͳ��ĳ����ǩ�ĵ����С�뾶�����б�ǩ��Ĵ�С�뾶
            if (d < min1[c]) {
                min2 = min(min2, min1[c]);
                min1[c] = d;
            }
            else if (d < min2) {
                min2 = d;
            }
        }
        int res = 0;
        for (auto m : min1) {
            if (m < min2) {
                ++res;
            }
        }
        return res;
    }
};
