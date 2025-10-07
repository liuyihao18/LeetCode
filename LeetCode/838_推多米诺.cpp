// 838_ÍÆ¶àÃ×Åµ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<pair<size_t, size_t>> q;
        vector<size_t> epoches(dominoes.size(), 0);
        for (size_t i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.') {
                q.emplace(i, 0);
            }
        }
        while (!q.empty()) {
            pair<size_t, size_t> curr = q.front();
            q.pop();
            size_t pos = curr.first;
            size_t epoch = curr.second;
            size_t next_p = pos;
            size_t next_e = epoch + 1;
            char dir = dominoes[pos];
            if (dir == 'L' && pos > 0) {
                next_p = pos - 1;
                if (dominoes[next_p] == 'R' && epoches[next_p] == next_e) {
                    dominoes[next_p] = '.';
                    continue;
                }
                else if (dominoes[next_p] == '.') {
                    dominoes[next_p] = 'L';
                    epoches[next_p] = next_e;
                }
                else {
                    continue;
                }
            }
            else if (dir == 'R' && pos + 1 < dominoes.size()) {
                next_p = pos + 1;
                if (dominoes[next_p] == 'L' && epoches[next_p] == next_e) {
                    dominoes[next_p] = '.';
                    continue;
                }
                else if (dominoes[next_p] == '.') {
                    dominoes[next_p] = 'R';
                    epoches[next_p] = next_e;
                }
                else {
                    continue;
                }
            }
            if (next_p != pos) q.emplace(next_p, next_e); 
        }
        return dominoes;
    }
};
