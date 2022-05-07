// 433_最小基因变化.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({ start, 0 });
        set<string> s;
        while (!q.empty()) {
            pair<string, int> curr = q.front();
            q.pop();
            string seq = curr.first;
            int cnt = curr.second;            
            if (seq == end) {
                return cnt;
            }
            if (s.count(seq)) {
                continue;
            }
            s.insert(seq);
            char genes[4] = { 'A','C','T','G' };
            for (size_t i = 0; i < curr.first.size(); i++) {
                for (auto gene : genes) {
                    if (seq[i] != gene) {
                        string new_seq = seq;
                        new_seq[i] = gene;
                        if (find(bank.begin(), bank.end(), new_seq) != bank.end()) {
                            q.push({ new_seq, cnt + 1 });
                        }
                    }
                }
            }
        }
        return -1;
    }
};
