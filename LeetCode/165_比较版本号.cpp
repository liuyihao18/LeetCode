// 165_±È½Ï°æ±¾ºÅ.cpp
#include "stdafx.h"
ustd

class Solution {
    vector<int> split(const string& version) {
        vector<int> _version;
        string num;
        for (char c : version) {
            if (c == '.') {
                _version.push_back(stoi(num));
                num.clear();
            }
            else {
                num += c;
            }
        }
        _version.push_back(stoi(num));
        return _version;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> _version1 = split(version1);
        vector<int> _version2 = split(version2);
        while (_version1.size() < _version2.size()) {
            _version1.push_back(0);
        }
        while (_version1.size() > _version2.size()) {
            _version2.push_back(0);
        }
        if (_version1 < _version2) {
            return -1;
        }
        else if (_version1 > _version2) {
            return 1;
        }
        else {
            return 0;
        }
    }
};
