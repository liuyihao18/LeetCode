// 386_×ÖµäĞòÅÅÊı.cpp
#include "custom.h"
ustd

class Solution {
    void dfs(int num, int n, vector<int>& result){
        for (int i = 0; i < 10; i++) {
            int temp = num * 10 + i;
            if (temp <= n) {
                result.push_back(temp);
                dfs(temp, n, result);
            }
            else {
                break;
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; i++) {
            if (i <= n) {
                result.push_back(i);
                dfs(i, n, result);
            }
            else {
                break;
            }
        }
        return result;
    }
};