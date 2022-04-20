// 388_文件的最长绝对路径.cpp
#include "custom.h"
ustd

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> paths;
        paths.push("");
        int result = 1;

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
                    paths.pop();
                }
                string path = paths.top() + "/" + name;
                if (name.find(".") != string::npos) {
                    result = max(result, static_cast<int>(path.size()));
                }
                paths.push(path);
            }
        }
        return --result;
    }
};
