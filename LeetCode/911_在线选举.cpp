// 911_在线选举.cpp
#include "stdafx.h"
ustd

class TopVotedCandidate {
    map<int, int> winner;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int, size_t> count;
        size_t max_count = 0;
        int top_person = 0;
        for (size_t i = 0; i < times.size(); i++) {
            if (++count[persons[i]] >= max_count) {
                max_count = count[persons[i]];
                top_person = persons[i];
            }
            winner.insert({ times[i], top_person });
        }
    }

    int q(int t) {
        return (--winner.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
