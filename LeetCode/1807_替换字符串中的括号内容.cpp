// 1807_Ìæ»»×Ö·û´®ÖÐµÄÀ¨ºÅÄÚÈÝ.cpp
#include "custom.h"
ustd

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> um;
        for (const auto& k : knowledge) {
            um[k[0]] = k[1];
        }
        string result, word;
        bool in = false;
        for (auto c : s) {
            if (c == '(') {
                word.clear();
                in = true;
            }
            else if (c == ')') {
                if (um.count(word)) {
                    result += um[word];
                }
                else {
                    result += '?';
                }
                in = false;
            }
            else {
                if (in) {
                    word += c;
                }
                else {
                    result += c;
                }
            }
        }
        return result;
    }
};
