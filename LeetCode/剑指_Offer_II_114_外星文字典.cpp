// ½£Ö¸_Offer_II_114_ÍâÐÇÎÄ×Öµä.cpp
#include "stdafx.h"
ustd

class Solution {
    using Node = size_t;
    const size_t NODE_NUM = 26;
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) {
            return "";
        }
        if (words.size() == 1) {
            return words.front();
        }
        vector<vector<bool>> graph(NODE_NUM, vector<bool>(NODE_NUM, false));
        set<Node> nodes;
        vector<int> inDegrees(NODE_NUM, 0);
        for (size_t i = 0; i + 1 < words.size(); i++) {
            for (size_t j = i + 1; j < words.size(); j++) {
                const string& word1 = words[i];
                const string& word2 = words[j];
                for (auto c1 : word1) {
                    nodes.insert(static_cast<size_t>(c1) - 'a');
                }
                for (auto c2 : word2) {
                    nodes.insert(static_cast<size_t>(c2) - 'a');
                }
                size_t size = min(word1.size(), word2.size());
                bool same = true;
                for (size_t k = 0; k < size; k++) {
                    Node c1 = static_cast<size_t>(word1[k]) - 'a';
                    Node c2 = static_cast<size_t>(word2[k]) - 'a';
                    if (c1 != c2) {
                        same = false;
                        if (graph[c1][c2] != true) {
                            graph[c1][c2] = true;
                            inDegrees[c2]++;
                        }
                        break;
                    }
                }
                if (same && word1.size() > word2.size()) {
                    return "";
                }
            }
        }
        string result = "";
        while (nodes.size() > 0) {
            Node u = -1;
            for (auto node : nodes) {
                if (inDegrees[node] == 0) {
                    u = node;
                    break;
                }
            }
            if (u == -1) {
                return "";
            }
            for (Node v = 0; v < graph[u].size(); v++) {
                if (graph[u][v]) {
                    inDegrees[v]--;
                }
            }
            result.push_back(static_cast<char>(u + 'a'));
            nodes.erase(u);
        }
        return result;
    }
};
