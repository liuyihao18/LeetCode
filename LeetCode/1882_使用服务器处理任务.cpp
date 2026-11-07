// 1882_使用服务器处理任务.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Server {
        int id;
        int weight;
        bool operator<(const Server& server) const {
            return (weight > server.weight
                || (weight == server.weight && id > server.id));
        }
    };
    struct FlyingTask {
        int serverId;
        long long finishTime;
        bool operator<(const FlyingTask& task) const {
            return (finishTime > task.finishTime);
        }
    };

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<Server, vector<Server>> serverList;
        for (int i = 0, n = static_cast<int>(servers.size()); i < n; i++) {
            serverList.emplace(Server{ i, servers[i] });
        }
        priority_queue<FlyingTask, vector<FlyingTask>> taskList;
        queue<int> waitingList;
        vector<int> ans;
        for (int i = 0, n = static_cast<int>(tasks.size()); i < n; i++)
        {
            while (!taskList.empty() && taskList.top().finishTime <= i)
            {
                const int serverId = taskList.top().serverId;
                serverList.emplace(Server{ serverId, servers[serverId] });
                taskList.pop();
            }
            waitingList.push(i);
            while (!waitingList.empty())
            {
                if (serverList.empty())
                {
                    break;
                }
                const Server server = serverList.top();
                serverList.pop();
                const int taskId = waitingList.front();
                waitingList.pop();
                taskList.push(FlyingTask{ server.id, i + tasks[taskId] });
                ans.push_back(server.id);
            }
        }
        long long currentTime = static_cast<int>(tasks.size());
        while (!waitingList.empty())
        {
            // 若 serverList 为空，则 tick 到结束时间
            if (serverList.empty())
            {
                currentTime = taskList.top().finishTime;
                while (!taskList.empty() && taskList.top().finishTime <= currentTime)
                {
                    const int serverId = taskList.top().serverId;
                    serverList.emplace(Server{ serverId, servers[serverId] });
                    taskList.pop();
                }
            }
            const Server server = serverList.top();
            serverList.pop();
            const int taskId = waitingList.front();
            waitingList.pop();
            taskList.push(FlyingTask{ server.id, currentTime + tasks[taskId] });
            ans.push_back(server.id);
        }
        return ans;
    }
};