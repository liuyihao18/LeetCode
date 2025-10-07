// 1600_ÍõÎ»¼Ì³ÐË³Ðò.cpp
#include "stdafx.h"
ustd

class ThroneInheritance {
    string kingName;
    map<string, pair<bool, vector<string>>> family;
public:
    ThroneInheritance(string kingName) : kingName(kingName) {
        family[kingName] = { true, {} };
    }

    void birth(string parentName, string childName) {
        family[parentName].second.push_back(childName);
        family[childName] = { true, {} };
    }

    void death(string name) {
        family[name].first = false;
    }

    void getSuccessor(string x, vector<string>& curOrder) {
        if (family[x].first) {
            curOrder.push_back(x);
        }
        for (const auto& child : family[x].second) {
            getSuccessor(child, curOrder);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> curOrder;
        getSuccessor(kingName, curOrder);
        return curOrder;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
