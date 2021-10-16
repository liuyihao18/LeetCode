// 282_给表达式添加运算符.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long string2long(const string& str) {
        stringstream in(str);
        long long result;
        in >> result;
        return result;
    }
    long long compute(const string& formula) {
        stack<long long> operands;
        stack<char> operators;
        string sub_formula;
        map<char, size_t> priority = { {'+',1},{'-',1},{'*',2} };
        for (auto c : formula) {    
            if (isdigit(c)) {
                sub_formula.push_back(c);
            }
            else {
                if (sub_formula.front() == '0' && sub_formula.size() > 1) {
                    throw string("0开头的数字");
                }
                operands.push(string2long(sub_formula));
                sub_formula.clear();
                while (true) {
                    if (operators.empty() || priority.at(c) > priority.at(operators.top())) {
                        operators.push(c);
                        break;
                    }
                    else {
                        char to_compute = operators.top();
                        operators.pop();
                        long long operand2 = operands.top();
                        operands.pop();
                        long long operand1 = operands.top();
                        operands.pop();
                        switch (to_compute)
                        {
                        case '+':
                            operands.push(operand1 + operand2);
                            break;
                        case '-':
                            operands.push(operand1 - operand2);
                            break;
                        case '*':
                            operands.push(operand1 * operand2);
                            break;
                        default:
                            return 0;
                        }
                    }
                }
            }
        }
        if (sub_formula.front() == '0' && sub_formula.size() > 1) {
            throw string("0开头的数字");
        }
        operands.push(string2long(sub_formula));
        sub_formula.clear();
        while (!operators.empty()) {
            char to_compute = operators.top();
            operators.pop();
            long long operand2 = operands.top();
            operands.pop();
            long long operand1 = operands.top();
            operands.pop();
            switch (to_compute)
            {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            default:
                return 0;
            }
        }
        return operands.top();
    }
    vector<string> addOperators(string num, long long target) {
        vector<string> result;
        for (size_t i = 0; i < (1 << 2 * (num.size() - 1)); ++i) {
            size_t copy_i = i;
            string copy_num = num;
            for (auto iter = copy_num.begin() + 1; iter != copy_num.end(); ++iter) {
                if (copy_i % 4 == 0) {
                    /* 不加符号 */
                }
                else if (copy_i % 4 == 1) {
                    /* 加号 */
                    iter = copy_num.insert(iter, '+');
                    ++iter;
                }
                else if (copy_i % 4 == 2) {
                    /* 减号 */
                    iter = copy_num.insert(iter, '-');
                    ++iter;
                }
                else {
                    /* 乘号 */
                    iter = copy_num.insert(iter, '*');
                    ++iter;
                }
                copy_i /= 4;
            }
            try {
                if (compute(copy_num) == target) {
                    result.push_back(copy_num);
                }
            }
            catch (string) {
            }
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        vector<string> ans;

        function<void(string&, int, long, long)> backtrack = [&](string& expr, int i, long res, long mul) {
            if (i == n) {
                if (res == target) {
                    ans.emplace_back(expr);
                }
                return;
            }
            int signIndex = expr.size();
            if (i > 0) {
                expr.push_back(0); // 占位，下面填充符号
            }
            long val = 0;
            // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导零
            for (int j = i; j < n && (j == i || num[i] != '0'); ++j) {
                val = val * 10 + num[j] - '0';
                expr.push_back(num[j]);
                if (i == 0) { // 表达式开头不能添加符号
                    backtrack(expr, j + 1, val, val);
                }
                else { // 枚举符号
                    expr[signIndex] = '+'; backtrack(expr, j + 1, res + val, val);
                    expr[signIndex] = '-'; backtrack(expr, j + 1, res - val, -val);
                    expr[signIndex] = '*'; backtrack(expr, j + 1, res - mul + mul * val, mul * val);
                }
            }
            expr.resize(signIndex);
        };

        string expr;
        backtrack(expr, 0, 0, 0);
        return ans;
    }
};
*/
/*
* 作者：LeetCode - Solution
* 链接：https ://leetcode-cn.com/problems/expression-add-operators/solution/gei-biao-da-shi-tian-jia-yun-suan-fu-by-2o1s7/
* 来源：力扣（LeetCode）
* 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/