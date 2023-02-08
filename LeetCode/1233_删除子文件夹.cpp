// 1233_É¾³ý×ÓÎÄ¼þ¼Ð.cpp
#include "custom.h"
ustd

class Solution {
    vector<string> split(const string& folder) {
        vector<string> res;
        string temp;
        for (auto c : folder) {
            if (c == '/') {
                if (!temp.empty()) {
                    res.push_back(temp);
                    temp.clear();
                }
            }
            temp += c;
        }
        if (!temp.empty()) {
            res.push_back(temp);
        }
        return res;
    }
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(), folders.end());
        set<string> parent;
        for (const auto& folder : folders) {
            vector<string> dir = split(folder);
            bool isChild = false;
            string temp;
            for (const auto& d : dir) {
                temp += d;
                if (parent.count(temp)) {
                    isChild = true;
                    break;
                }
            }
            if (!isChild) {
                parent.insert(folder);
            }
        }
        return vector<string>(parent.begin(), parent.end());
    }
};
