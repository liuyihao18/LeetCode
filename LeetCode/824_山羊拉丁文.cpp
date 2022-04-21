// 824_É½ÑòÀ­¶¡ÎÄ.cpp
#include "custom.h"
ustd

class Solution {
public:
    string toGoatLatin(string sentence) {
        sentence.push_back(' ');
        string result;
        string word;
        string suffix;
        for (auto c : sentence) {
            if (c == ' ') {
                size_t offset = 0;
                switch (word.front())
                {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    break;
                default:
                    word += word.front();
                    offset = 1;
                    break;
                }
                word += "ma";
                word += (suffix += "a");
                result += word.substr(offset) + " ";
                word = "";
            }
            else {
                word += c;
            }
        }
        result.pop_back();
        return result;
    }
};
