// 1079_»î×ÖÓ¡Ë¢.cpp
#include "stdafx.h"
ustd

class Solution {
    int A(int m, int n) {
        int result = 1;
        for (int i = 0; i < n; i++, m--) {
            result *= m;
        }
        return result;
    }
public:
    int numTilePossibilities(string tiles) {
        int result = 0;
        set<map<char, int>> visited;
        size_t l = tiles.length();
        for (size_t s = 1; s < (static_cast<size_t>(1) << l); s++) {
            map<char, int> visit;
            int tl = 0;
            for (size_t i = 0; i < l; i++) {
                if (s >> i & 1) {
                    visit[tiles[i]]++;
                    tl++;
                }
            }
            if (!visited.count(visit)) {
                visited.insert(visit);
                int temp = 1;
                temp *= A(tl, tl);
                for (auto& [_, count] : visit) {
                    temp /= A(count, count);
                }
                result += temp;
            }
        }
        return result;
    }
};
