// 1001_Íø¸ñÕÕÃ÷.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int, size_t> rows;
        map<int, size_t> cols;
        map<int, size_t> main_diags;
        map<int, size_t> sub_diags;
        set<vector<int>> opened;
        for (const auto& lamp : lamps) {
            if (!opened.count(lamp)) {
                opened.insert(lamp);
                int i = lamp.front();
                int j = lamp.back();
                rows[i]++;
                cols[j]++;
                main_diags[i - j]++;
                sub_diags[i + j]++;
            }
        }
        vector<int> result;
        for (const auto& query : queries) {
            int i = query.front();
            int j = query.back();
            // ÕÕÁÁ
            if (rows[i] > 0 ||
                cols[j] > 0 ||
                main_diags[i - j] > 0 ||
                sub_diags[i + j] > 0)
            { 
                result.push_back(1);
                // ¹ØµÆ
                for (int ii = -1; ii <= 1; ii++) {
                    for (int jj = -1; jj <= 1; jj++) {
                        int iii = i + ii;
                        int jjj = j + jj;
                        if (iii >= 0 && iii < n && jjj >= 0 && jjj < n) {
                            auto iter = opened.find({ iii, jjj });
                            if (iter != opened.end()) {
                                opened.erase(iter);
                                rows[iii]--;
                                cols[jjj]--;
                                main_diags[iii - jjj]--;
                                sub_diags[iii + jjj]--;
                            }
                        }
                    }
                }
            }
            else {
                result.push_back(0);
            }
        }
        return result;
    }
};
