// 535_TinyURL_的加密与解密.cpp
#include "stdafx.h"
ustd

class Solution {
    map<int, string> m;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int i;
        while (m.count(i = rand())) {
            if (m[i] == longUrl) {
                break;
            }
        }
        m[i] = longUrl;
        return to_string(i);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = stoi(shortUrl);
        return m[i];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
