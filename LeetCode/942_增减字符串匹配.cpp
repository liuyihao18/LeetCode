// 942_Ôö¼õ×Ö·û´®Æ¥Åä.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result;
        int min = 0;
        int max = static_cast<int>(s.size());
        for (auto c : s) {
            if (c == 'I') {
                result.push_back(min++);
            }
            else {
                result.push_back(max--);
            }
        }
        result.push_back(min); // min == max
        return result;
    }
};
