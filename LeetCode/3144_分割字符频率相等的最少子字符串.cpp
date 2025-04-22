// 3144_�ָ��ַ�Ƶ����ȵ��������ַ���.cpp
#include "custom.h"
ustd

class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int minimumSubstringsInPartition(string s) {
        int n = static_cast<int>(s.size());
        vector<int> d(n + 1, inf); // d[i]��ʾ��i��β��ǰ׺�ַ�������ƽ���ַ��������ٸ���
        unordered_map<char, int> occ_cnt;
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            int max_cnt = 0;
            occ_cnt.clear();
            for (int j = i; j >= 1; j--) {
                occ_cnt[s[j - 1]]++;
                max_cnt = max(max_cnt, occ_cnt[s[j - 1]]);
                // �ж��Ƿ���ƽ���ַ����ȼ��ڡ������ַ����ִ������ڳ��������ַ���������Լ��Ϊһ���˷�
                if (max_cnt * occ_cnt.size() == (i - j + 1) && d[j - 1] != inf) {
                    d[i] = min(d[i], d[j - 1] + 1); // ת�Ʒ��̣��Ӻ���ǰ���㣬��s[i]��s[j]֮�乹��ƽ���ַ���
                }
            }
        }
        return d[n];
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency/solutions/2886822/fen-ge-zi-fu-pin-lu-xiang-deng-de-zui-sh-ofpv/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
