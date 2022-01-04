// 913_猫和老鼠.cpp
#include "custom.h"
ustd

/* 不会做 */
class Solution {
    struct State{
        int mouse;
        int cat;
        bool operator<(const State& s) const {
            return mouse < s.mouse || mouse == s.mouse && cat < s.cat;
        }
    };
public:
    int catMouseGame(vector<vector<int>>& graph) {
        set<State> visited;
        State init{ 1,2 };
        queue<State> q;
        q.push(init);
        int turn = 1;
        while (!q.empty()) {
            State state = q.front();
            q.pop();
            if (visited.find(state) != visited.end()) {
                continue;
            }            
        }
    }
};

/*
const int MOUSE_WIN = 1;
const int CAT_WIN = 2;
const int DRAW = 0;
const int MAXN = 51;

class Solution {
public:
    int n;
    int dp[MAXN][MAXN][MAXN * 2];
    vector<vector<int>> graph;

    int catMouseGame(vector<vector<int>>& graph) {
        this->n = graph.size();
        this->graph = graph;
        memset(dp, -1, sizeof(dp));
        return getResult(1, 2, 0);
    }

    int getResult(int mouse, int cat, int turns) {
        if (turns == n * 2) {
            return DRAW;
        }
        if (dp[mouse][cat][turns] < 0) {
            if (mouse == 0) {
                dp[mouse][cat][turns] = MOUSE_WIN;
            }
            else if (cat == mouse) {
                dp[mouse][cat][turns] = CAT_WIN;
            }
            else {
                getNextResult(mouse, cat, turns);
            }
        }
        return dp[mouse][cat][turns];
    }

    void getNextResult(int mouse, int cat, int turns) {
        int curMove = turns % 2 == 0 ? mouse : cat;
        int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
        int result = defaultResult;
        for (int next : graph[curMove]) {
            if (curMove == cat && next == 0) {
                continue;
            }
            int nextMouse = curMove == mouse ? next : mouse;
            int nextCat = curMove == cat ? next : cat;
            int nextResult = getResult(nextMouse, nextCat, turns + 1);
            if (nextResult != defaultResult) {
                result = nextResult;
                if (result != DRAW) {
                    break;
                }
            }
        }
        dp[mouse][cat][turns] = result;
    }
};
*/
/*
作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/cat-and-mouse/solution/mao-he-lao-shu-by-leetcode-solution-444x/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
