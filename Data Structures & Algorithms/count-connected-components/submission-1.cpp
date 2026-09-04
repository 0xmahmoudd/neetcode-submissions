#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef unordered_map<int, vector<int>> GRAPH;

class Solution
{
private:


void build(vector<vector<int>> &edges, GRAPH &graph)
{
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}

void dfs(GRAPH &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (int i : graph[node])
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}

public:
    int countComponents(int nodes, vector<vector<int>> &edges)
    {
        GRAPH graph;
        build(edges, graph);
        vector<bool> visited(nodes);
        int count = 0;
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(graph, visited, i);
            }
        }
        return count;
    }    
};
