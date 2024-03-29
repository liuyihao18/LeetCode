// 385_迷你语法分析器.cpp
#include "custom.h"
ustd


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
   // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '-') {
                negative = true;
            }
            else if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else if (c == '[') {
                st.emplace(NestedInteger());
            }
            else if (c == ',' || c == ']') {
                if (isdigit(s[i - 1])) {
                    if (negative) {
                        num *= -1;
                    }
                    st.top().add(NestedInteger(num));
                }
                num = 0;
                negative = false;
                if (c == ']' && st.size() > 1) {
                    NestedInteger ni = st.top();
                    st.pop();
                    st.top().add(ni);
                }
            }
        }
        return st.top();
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/mini-parser/solution/mi-ni-yu-fa-fen-xi-qi-by-leetcode-soluti-l2ma/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/