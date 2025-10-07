// 1061_按字典序排列最小的等效字符串.cpp
#include "stdafx.h"
ustd

class Solution {
    const size_t N = 26;
    size_t alphaToIndex(char c) {
        return static_cast<size_t>(c - 'a');
    }
    char indexToAlpha(size_t index) {
        return static_cast<char>(index + 'a');
    }
    vector<size_t> getConnectedComponent(const vector<vector<size_t>>& graph, size_t start, vector<size_t>& belong, size_t ith) {
        vector<size_t> connectedComponent;
        stack<size_t> st;
        st.push(start);
        while (!st.empty()) {
            size_t u = st.top();
            st.pop();
            if (belong[u] != -1) {
                continue;
            }
            belong[u] = ith;
            connectedComponent.push_back(u);
            for (size_t v : graph[u]) {
                st.push(v);
            }
        }
        return connectedComponent;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<size_t>> graph(N);
        for (size_t i = 0; i < s1.size(); i++) {
            size_t u = alphaToIndex(s1[i]);
            size_t v = alphaToIndex(s2[i]);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<vector<size_t>> connectedComponents;
        vector<size_t> belong(N, -1);
        size_t ith = 0;
        for (size_t i = 0; i < N; i++) {
            if (belong[i] == -1) {
                vector<size_t> connectedComponent = getConnectedComponent(graph, i, belong, ith);
                connectedComponents.push_back(std::move(connectedComponent));
                ith++;
            }
        }
        for (char& c : baseStr) {
            c = indexToAlpha(connectedComponents[belong[alphaToIndex(c)]][0]);
        }
        return baseStr;
    }
};
