// 822_·­×ª¿¨Æ¬ÓÎÏ·.cpp
#include "custom.h"
ustd

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int minCard = INT_MAX;
        for (size_t i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                continue;
            }
            if (fronts[i] < minCard) {
                int temp = fronts[i];
                bool check = true;
                for (size_t j = 0; j < fronts.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    int front = fronts[j];
                    int back = backs[j];
                    if (front == temp && back == temp) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    minCard = temp;
                }
            }
            if (backs[i] < minCard) {
                int temp = backs[i];
                bool check = true;
                for (size_t j = 0; j < fronts.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    int front = fronts[j];
                    int back = backs[j];
                    if (front == temp && back == temp) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    minCard = temp;
                }
            }

        }
        return minCard == INT_MAX ? 0 : minCard;
    }
};
