// 1606_找到处理最多请求的服务器.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Server {
        int id;
        int count;
        bool operator<(const Server& s) const {
            return count < s.count || id < s.id && count == s.count;
        }
    };
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> over(k, 0);
        vector<int> counts(k, 0);
        int n = static_cast<int>(arrival.size());
        over[0] = arrival[0] + load[0];
        int min_over = 0;
        for (int i = 1; i < arrival.size(); i++) {
            if (arrival[i] < min_over) {
                continue;
            }
            int j = i % k;
            int temp = INT_MAX;
            while (arrival[i] < over[j]) {
                temp = min(temp, over[j]);
                j = (j + 1) % k;
                if (j == i % k) {
                    min_over = temp;
                    break;
                }
            }
            if (arrival[i] >= over[j]) {
                if (over[j] != 0) {
                    counts[j]++;
                }
                over[j] = arrival[i] + load[i];
            }
        }
        set<Server> ss;
        for (int i = 0; i < k; i++) {
            if (over[i]) {
                counts[i]++;
                over[i] = 0;
            }
            ss.insert({ i, counts[i] });
        }
        vector<int> result;
        result.push_back(ss.rbegin()->id);
        for (set<Server>::reverse_iterator iter = ++ss.rbegin(); iter != ss.rend(); ++iter) {
            if (iter->count == counts[result.back()]) {
                result.push_back(iter->id);
            }
            else {
                break;
            }
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requests(k);
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            requests[*p]++;
            busy.emplace(arrival[i] + load[i], *p);
            available.erase(p);
        }
        int maxRequest = *max_element(requests.begin(), requests.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            if (requests[i] == maxRequest) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
*/
