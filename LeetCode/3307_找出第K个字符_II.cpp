// 3307_ÕÒ³öµÚK¸ö×Ö·û_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        stack<long long> st;
        st.push(k);
        long long base = static_cast<long long>(log2(k));
        while (base >= 0) {
            if (k > (1LL << base)) {
                k -= 1LL << base;
            }
            st.push(k);
            base--;
        }
        char result = 'a';
        long long from = st.top();
        st.pop();
        for (size_t i = 0; i < operations.size() && !st.empty(); i++) {
            int operation = operations[i];
            long long to = st.top();
            st.pop();
            if (operation == 1 && to != from) {
                result++;
                if (result > 'z') {
                    result = 'a';
                }
            }
            from = to;
        }
        return result;
    }
};
