// 面试题_01_05_一次编辑.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n1 = static_cast<int>(first.size());
        int n2 = static_cast<int>(second.size());
        if (n1 < n2) {
            swap(first, second); // 保证first不比second短
            swap(n1, n2);
        }
        int diff = n1 - n2;
        if (diff > 1) {
            return false;
        }
        int count = 0;
        for (size_t i = 0; i < first.size(); i++) {
            if (first[i] != second[i]) {
                if (++count > 1) {
                    return false;
                }
                if (diff == 1) {
                    first.erase(i, 1);
                    i--;
                }
            }
        }
        return true;
    }
};
