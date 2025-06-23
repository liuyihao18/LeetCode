// 3170_É¾³ýÐÇºÅÒÔºó×ÖµäÐò×îÐ¡µÄ×Ö·û´®.cpp
#include "custom.h"
ustd

class Solution {
public:
    string clearStars(string s) {
        size_t n = s.size();
        vector<bool> deleteFlag(n, false);
        vector<vector<size_t>> indexes(26, vector<size_t>());
        for (size_t i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (vector<size_t>& index : indexes) {
                    if (!index.empty()) {
                        deleteFlag[index.back()] = true;
                        index.pop_back();
                        break;
                    }
                }
                deleteFlag[i] = true;
            }
            else {
                indexes[static_cast<size_t>(s[i] - 'a')].push_back(i);
            }
        }
        string result;
        for (size_t i = 0; i < n; i++) {
            if (!deleteFlag[i]) {
                result += s[i];
            }
        }
        return result;
    }
};
