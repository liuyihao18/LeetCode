// 946_—È÷§’ª–Ú¡–.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        stack<int> st;
        size_t i = 0, j = 0;
        while (j < popped.size()) {
            while (st.empty() || st.top() != popped[j]) {
                if (i < pushed.size()) {
                    st.push(pushed[i]);
                    i++;
                }
                else {
                    return false;
                }
            }
            st.pop();
            j++;
        }
        return true;
    }
};
