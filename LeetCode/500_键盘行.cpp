// 500_¼üÅÌÐÐ.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        const vector<string> can_prints = { "qwertyuiop","asdfghjkl","zxcvbnm" };
        vector<string> result;
        for (auto word : words) {
            for (auto can_print : can_prints) {
                bool add = true;
                for (auto cap : word) {
                    if (can_print.find(tolower(cap)) == string::npos) {
                        add = false;
                        break;
                    }
                }
                if (add) {
                    result.push_back(word);
                    break;
                }
            }
        }
        return result;
    }
};