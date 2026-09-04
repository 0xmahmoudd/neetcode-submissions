#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
}




vector<int> topsort(GRAPH &adjList)
{
    int sz = adjList.size();
    vector<int> indegree(sz, 0);
    vector<int> ans;

    for (int i = 0; i < sz; i++)
    {
        for (int j : adjList[i])
        {
            indegree[j]++;
        }
    }

    queue<int> ready;

    for (int i = 0; i < sz; i++)
    {
        if (indegree[i] == 0)
        {
            ready.push(i);
        }
    }

    while (!ready.empty())
    {
        int i = ready.front();
        ready.pop();
        ans.push_back(i);

        for (int j : adjList[i])
        {
            if (--indegree[j] == 0) ready.push(j);
        }

    }

    if (ans.size() != adjList.size())
    {
        ans.clear();
    }
    return ans;
}


class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        GRAPH graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            add_directed_edge(graph, prerequisites[i][1], prerequisites[i][0]);
        }
        vector<int> ans = topsort(graph);
        return ans.size() == numCourses;
    }
};