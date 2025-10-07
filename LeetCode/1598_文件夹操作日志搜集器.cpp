// 1598_文件夹操作日志搜集器.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (const string& log : logs) {
            if (log == "../") { if (result > 0) result--; }
            else if (log == "./");
            else result++;
        }
        return result;
    }
};
