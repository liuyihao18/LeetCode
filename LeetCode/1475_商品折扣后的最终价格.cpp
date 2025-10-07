// 1475_商品折扣后的最终价格.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    /*
    vector<int> finalPrices(vector<int>& prices) {
        // vector<int> result(prices.begin(), prices.end());
        vector<int>& result = prices;
        for (size_t i = 0; i + 1 < result.size(); i++) {
            for (size_t j = i + 1; j < result.size(); j++) {
                if (result[i] >= result[j]) {
                    result[i] -= result[j];
                    break;
                }
            }
        }
        return result;
    }
    */
    vector<int> finalPrices(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            result[i] = st.empty() ? prices[i] : prices[i] - st.top();
            st.push(prices[i]);
        }
        return result;
    }
};
