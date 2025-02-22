// 2506_统计相似字符串对的数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<unsigned> wordsBitmap;
        transform(words.begin(), words.end(), back_inserter(wordsBitmap),
            [](const string& word) {
                unsigned bitmap = 0;
                for (auto c : word) {
                    bitmap |= 1 << (c - 'a');
                }
                return bitmap;
            }
        );
        sort(wordsBitmap.begin(), wordsBitmap.end());
        size_t i = 0, j = 0;
        int answer = 0;
        while (j < wordsBitmap.size()) {
            while (j < wordsBitmap.size() && wordsBitmap[j] == wordsBitmap[i]) {
                j++;
            }
            answer += static_cast<int>((j - i) * (j - i - 1) / 2);
            i = j;
        }
        return answer;
    }
};
