// 677_¼üÖµÓ³Éä.cpp
#include "custom.h"
ustd

class MapSum {
    map<string, int> _map;
public:
    MapSum() {

    }

    void insert(string key, int val) {
        _map[key] = val;
    }

    int sum(string prefix) {
#ifdef MAP_REDUCE
            auto i = _map.lower_bound(prefix);
            ++prefix.back();
            auto j = _map.lower_bound(prefix);
            return transform_reduce(i, j, 0, plus{}, [](auto&& i) {return i.second; });
#endif // MAP_REDUCE
        int sum = 0;
        for (auto p : _map) {
            if (p.first.find(prefix) == 0) {
                sum += p.second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */