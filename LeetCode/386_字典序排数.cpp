// 386_×ÖµäÐòÅÅÊý.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        stack<int> st;
        for (int i = 9; i >= 1; i--) {
            if (i <= n) {
                st.push(i);
            }
        }
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
                result.push_back(curr);
                for (int i = 9; i >= 0; i--) {
                    if (curr * 10 + i <= n) {
                        st.push(curr * 10 + i);
                    }
                }
        }
        return result;
    }
};

/*
class Solution {
    void dfs(int num, int n, vector<int>& result){
        for (int i = 0; i < 10; i++) {
            int temp = num * 10 + i;
            if (temp <= n) {
                result.push_back(temp);
                dfs(temp, n, result);
            }
            else {
                break;
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; i++) {
            if (i <= n) {
                result.push_back(i);
                dfs(i, n, result);
            }
            else {
                break;
            }
        }
        return result;
    }
};
*/
