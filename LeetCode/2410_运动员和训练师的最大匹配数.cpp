// 2410_运动员和训练师的最大匹配数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
		sort(players.begin(), players.end());
		sort(trainers.begin(), trainers.end());
		int ans = 0;
		size_t i = 0, j = 0;
		while (i < players.size() && j < trainers.size()) {
			if (players[i] <= trainers[j]) {
				ans++;
				i++;
				j++;
			}
			else {
				j++;
			}
		}
		return ans;
    }
};
