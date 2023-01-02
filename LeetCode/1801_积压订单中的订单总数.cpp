// 1801_积压订单中的订单总数.cpp
#include "custom.h"
ustd

class Solution {
    struct buyCmp {
        bool operator()(const vector<int>& order1, const vector<int>& order2) const {
            return order1[0] < order2[0];
        }
    };
    struct sellCmp {
        bool operator()(const vector<int>& order1, const vector<int>& order2) const {
            return order1[0] > order2[0];
        }
    };
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int remainder = (int)1e9 + 7;
        priority_queue<vector<int>, vector<vector<int>>, buyCmp> buys;
        priority_queue<vector<int>, vector<vector<int>>, sellCmp> sells;
        for (auto& order : orders) {
            if (order[2] == 0) {
                // buy
                while (order[1] > 0 && !sells.empty() && sells.top()[0] <= order[0]) {
                    if (order[1] >= sells.top()[1]) {
                        order[1] -= sells.top()[1];
                        sells.pop();
                    }
                    else {
                        vector<int> sell = sells.top();
                        sells.pop();
                        sell[1] -= order[1];
                        order[1] = 0;
                        sells.emplace(sell);
                    }
                }
                if (order[1] > 0) {
                    buys.emplace(order);
                }
            }
            else {
                // sell
                while (order[1] > 0 && !buys.empty() && buys.top()[0] >= order[0]) {
                    if (order[1] >= buys.top()[1]) {
                        order[1] -= buys.top()[1];
                        buys.pop();
                    }
                    else {
                        vector<int> buy = buys.top();
                        buys.pop();
                        buy[1] -= order[1];
                        order[1] = 0;
                        buys.emplace(buy);
                    }
                }
                if (order[1] > 0) {
                    sells.emplace(order);
                }
            }
        }
        int result = 0;
        while (!buys.empty()) {
            result = (result + buys.top()[1]) % remainder;
            buys.pop();
        }
        while (!sells.empty()) {
            result = (result + sells.top()[1]) % remainder;
            sells.pop();
        }
        return result;
    }
};
