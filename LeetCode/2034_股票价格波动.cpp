// 2034_股票价格波动.cpp
#include "custom.h"
ustd

class StockPrice {
    map<int, int> m;
    pair<int, int> curr{ 0, 0 };
    multiset<int> prices;
public:
    StockPrice() {

    }

    void update(int timestamp, int price) {
        int prePrice = m.find(timestamp) == m.end() ? 0 : m[timestamp];
        m[timestamp] = price;
        if (timestamp >= curr.first) {
            curr = { timestamp, price };
        }
        if (prePrice > 0) {
            auto iter = prices.find(prePrice);
            if (iter != prices.end()) {
                prices.erase(iter);
            }
        }
        prices.insert(price);
    }

    int current() {
        return curr.second;
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
