// 860_ÄûÃÊË®ÕÒÁã.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash5 = 0, cash10 = 0, cash20 = 0;
        for (auto bill : bills) {
            if (bill == 5) {
                cash5++;
            }
            else if (bill == 10) {
                if (cash5 > 0) {
                    cash5--;
                    cash10++;
                }
                else {
                    return false;
                }
            }
            else if (bill == 20) {
                if (cash10 > 0) {
                    cash10--;
                    if (cash5 > 0) {
                        cash5--;
                        cash20++;
                    }
                    else {
                        return false;
                    }
                }
                else if (cash5 > 2) {
                    cash5 -= 3;
                    cash20++;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};
