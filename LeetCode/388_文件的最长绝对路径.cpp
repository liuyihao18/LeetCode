// 388_文件的最长绝对路径.cpp
#include "custom.h"
ustd

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> st;
        st.push(-1);
        int result = 0;

        string name;
        int last_count = -1;
        int count = 0;
        for (size_t i = 0; i < input.size();) {
            if (input[i] == '\n') {
                name = "";
                last_count = count;
                count = 0;
                i++;
            }
            else if (input[i] == '\t') {
                count++;
                i++;
            }
            else {
                while (i < input.size() && input[i] != '\n') {
                    name += input[i];
                    i++;
                }
                for (int i = 0; i <= last_count - count; i++) {
                    st.pop();
                }
                int path_len = st.top() + 1 + static_cast<int>(name.size());
                if (name.find(".") != string::npos) {
                    result = max(result, path_len);
                }
                st.push(path_len);
            }
        }
        return result;
    }
};
