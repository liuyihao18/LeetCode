// 1754_构造字典序最大的合并字符串.cpp
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
作者：力扣官方题解
链接：https ://leetcode.cn/problems/largest-merge-of-two-strings/solutions/2030226/gou-zao-zi-dian-xu-zui-da-de-he-bing-zi-g6az1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
