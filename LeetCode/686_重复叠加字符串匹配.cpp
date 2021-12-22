// 686_ÖØ¸´µþ¼Ó×Ö·û´®Æ¥Åä.cpp
#include "custom.h"
ustd

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int times = 0;
        string temp;
        while (temp.size() < b.size()) {
            temp += a;
            times++;
        }
        if (temp.find(b) != string::npos) {
            return times;
        }
        temp += a;
        times++;
        if (temp.find(b) != string::npos) {
            return times;
        }
        return -1;
    }
};
