// 1021_É¾³ı×îÍâ²ãµÄÀ¨ºÅ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result;
        for (auto c : s) {
            if (c == '(') {
                st.push(c);
                if (st.size() > 1) {
                    result += c;
                }
            }
            else {
                st.pop();
                if (st.size() > 0) {
                    result += c;
                }
            }
        }
        return result;
    }
};
