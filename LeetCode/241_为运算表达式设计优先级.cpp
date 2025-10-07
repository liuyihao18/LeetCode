// 241_为运算表达式设计优先级.cpp
#include "stdafx.h"
ustd

const string operators = "+-*";
constexpr int add(int a, int b) { return a + b; }
constexpr int sub(int a, int b) { return a - b; }
constexpr int mul(int a, int b) { return a * b; }
const map<char, int(*)(int, int)> operator_map = {
    {'+', add},
    {'-', sub},
    {'*', mul},
};

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        size_t first_operator_pos = expression.find_first_of(operators);
        if (first_operator_pos == string::npos) {
            return { stoi(expression) };
        }
        size_t last_operator_pos = expression.find_last_of(operators);
        if (first_operator_pos == last_operator_pos) {
            char op = expression[first_operator_pos];
            int left = stoi(expression.substr(0, first_operator_pos));
            int right = stoi(expression.substr(first_operator_pos + 1));
            return { operator_map.at(op)(left,right) };
        }
        vector<int> result;
        for (size_t i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                vector<int> left_result = diffWaysToCompute(left);
                vector<int> right_result = diffWaysToCompute(right);
                for (size_t l = 0; l < left_result.size(); l++) {
                    for (size_t r = 0; r < right_result.size(); r++) {
                        result.push_back(operator_map.at(expression[i])(left_result[l], right_result[r]));
                    }
                }
            }
        }
        return result;
    }
};
