// 3121_统计特殊字母的数量_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int numberOfSpecialChars(string_view word) {
        vector<int> index(52, -1);
        for (int i = 0, n = static_cast<int>(word.size()); i < n; i++)
        {
	        if (word[i] >= 'a' && word[i] <= 'z')
	        {
                index[word[i] - 'a'] = i;
	        }
            else if (word[i] >= 'A' && word[i] <= 'Z' && index[word[i] - 'A' + 26] == -1)
            {
                index[word[i] - 'A' + 26] = i;
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            if (index[i] != -1 && index[i + 26] != -1 &&
                index[i] < index[i + 26])
            {
                result++;
            }
        }
        return result;
    }
};
