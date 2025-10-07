// 301_É¾³ýÎÞÐ§µÄÀ¨ºÅ.cpp
#include "stdafx.h"
ustd
#define BFS

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(') {
                st.push(c);
            }
            if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
    map<string, bool> result;
#ifdef DFS
    size_t max_length = 0;
    vector<string> removeInvalidParentheses(string s) {
        set<string> res;
        dfs(s, res);
        for (auto iter = res.begin(); iter != res.end();) {
            if (iter->size() < max_length) {
                iter = res.erase(iter);
            }
            else {
                ++iter;
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    void dfs(string s, set<string>& st) {
        if (result.find(s) != result.end()) {
            if (result.at(s) && s.size() >= max_length) {
                max_length = s.size();
                st.insert(s);
                return;
            }
            else {
                return;
            }
        }
        if (isValid(s) && s.size() >= max_length) {
            result[s] = true;
            max_length = s.size();
            st.insert(s);
            return;
        }
        result[s] = false;
        for (size_t i = 0; i < s.size(); i++) {
            string copy_s = s;
            if (copy_s[i] == '(' || copy_s[i] == ')') {
                copy_s.erase(i, 1);
                dfs(copy_s, st);
            }
        }
    }
#elif defined BFS
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        size_t max_length = 0;
        q.push(s);
        set<string> res;
        while (!q.empty()) {
            string s0 = q.front();
            q.pop();
            if (s0.size() < max_length) {
                break;
            }
            if (result.find(s0) != result.end()) {
                continue;
            }
            if (isValid(s0)) {
                max_length = s0.size();
                result[s0] = true;
                res.insert(s0);
            }
            result[s0] = false;
            for (size_t i = 0; i < s0.size(); i++) {
                string s1 = s0;
                if (s1[i] == '(' || s1[i] == ')') {
                    s1.erase(i, 1);
                    q.push(s1);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
#endif
};