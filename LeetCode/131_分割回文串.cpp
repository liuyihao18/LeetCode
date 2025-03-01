// 131_·Ö¸î»ØÎÄ´®.cpp
#include "custom.h"
ustd

class Solution {
    unordered_map<string, vector<vector<string>>> um;
    bool isPalindrome(const string& s) {
        if (s.empty()) {
            return false;
        }
        if (s.size() == 1) {
            return true;
        }
        size_t i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        if (um.count(s)) {
            return um[s];
        }
        set<vector<string>> result;
        if (isPalindrome(s)) {
            result.insert({ s });
        }
        if (s.size() > 1) {
            for (size_t i = 1; i < s.size(); i++) {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i);
                vector<vector<string>> result1 = partition(s1);
                vector<vector<string>> result2 = partition(s2);
                for (const auto& r1 : result1) {
                    for (const auto& r2 : result2) {
                        vector<string> temp;
                        copy(r1.begin(), r1.end(), back_inserter(temp));
                        copy(r2.begin(), r2.end(), back_inserter(temp));
                        result.insert(temp);
                    }
                }
            }
        }
        um[s] = vector<vector<string>>(result.begin(), result.end());
        return um[s];
    }
};
