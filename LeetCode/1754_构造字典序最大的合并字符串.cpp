// 1754_�����ֵ������ĺϲ��ַ���.cpp
#include "custom.h"
ustd

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge;
        string_view view1(word1), view2(word2);
        int i = 0, j = 0;
        while (i < view1.size() || j < view2.size()) {
            if (i < view1.size() && view1.substr(i) > view2.substr(j)) {
                merge.push_back(view1[i++]);
            }
            else {
                merge.push_back(view2[j++]);
            }
        }
        return merge;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/largest-merge-of-two-strings/solutions/2030226/gou-zao-zi-dian-xu-zui-da-de-he-bing-zi-g6az1/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
