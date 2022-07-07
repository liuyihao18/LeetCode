// 648_µ¥´ÊÌæ»».cpp
#include "custom.h"
ustd

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> s(dictionary.begin(), dictionary.end());
        sentence += ' ';
        string result;
        string word;
        for (auto c : sentence) {
            if (c != ' ') {
                word += c;
            }
            else {
                string prefix;
                for (size_t i = 0; i < word.size(); i++) {
                    prefix += word[i];
                    if (s.count(prefix)) {
                        break;
                    }
                }
                result += prefix;
                result += ' ';
                word.clear();
            }
        }
        result.pop_back();
        return result;
    }
};
