// 1832_�жϾ����Ƿ�Ϊȫ��ĸ��
#include "stdafx.h"
ustd

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> cnts(26, 0);
        for (auto c : sentence) {
            cnts[static_cast<size_t>(c - 'a')]++;
        }
        return all_of(cnts.begin(), cnts.end(), [](int cnt) { return cnt > 0; });
    }
};
