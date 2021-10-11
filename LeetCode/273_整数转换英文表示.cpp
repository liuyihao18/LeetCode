// 273_整数转换英文表示.cpp
#include "custom.h"
ustd

class Solution {
private:
    static map<int, string> number2word;
public:
    string number3ToWords(int num) {
        int gewei = num % 10;
        num /= 10;
        int shiwei = num % 10;
        num /= 10;
        int baiwei = num % 10;
        string result;
        if (baiwei != 0) {
            result += number2word[baiwei];
            result += " ";
            result += number2word[100];
            result += " ";
        }
        if (shiwei != 0) {
            if (shiwei == 1) {
                result += number2word[shiwei * 10 + gewei];
            }
            else {
                result += number2word[shiwei * 10];
                result += " ";
            }
        }
        if (shiwei != 1 && gewei != 0) {
            result += number2word[gewei];
        }
        if (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
    string numberToWords(int num) {
        if (num == 0) {
            return number2word[num];
        }
        string result;
        int base = 1;
        while (num != 0) {
            int res = num % 1000;
            if (res != 0) {
                string temp_result = number3ToWords(num % 1000);
                if (base != 1) {
                    result = temp_result + " " + number2word[base] + " " + result;
                }
                else {
                    result = temp_result + result;
                }
            }
            num /= 1000;
            if (base == 1000000000) {

            }
            else {
                base *= 1000;
            }
        }
        if (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};

map<int, string> Solution::number2word = {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"},
    {20, "Twenty"},
    {30, "Thirty"},
    {40, "Forty"},
    {50, "Fifty"},
    {60, "Sixty"},
    {70, "Seventy"},
    {80, "Eighty"},
    {90, "Ninety"},
    {100, "Hundred"},
    {1000,"Thousand"},
    {1000000, "Million"},
    {1000000000, "Billion"}
};