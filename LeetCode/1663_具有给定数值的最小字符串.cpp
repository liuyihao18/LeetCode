// 1663_具有给定数值的最小字符串.cpp
#include "custom.h"
ustd

class Solution {
public:
    string getSmallestString(int n, int k) {
        string temp;
        while (n > 0 && n < k) {
            int x = min(k - n, 26);
            temp += 'a' + x - 1;
            k -= x;
            n--;
        }
        while (n > 0) {
            temp += 'a';
            n--;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
