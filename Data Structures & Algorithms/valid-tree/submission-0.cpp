#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 10000000;  // A big value expressing infinity

void add_undirected_edge(GRAPH &graph, int from, int to) 
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

class Solution
{
private:

    bool bfs_cycle(GRAPH &graph, int start, vector<int> &len, vector<int> &parent)
    {
        queue<int> q;
        q.push(start);
        len[start] = 0;

        for (int level = 0, size = 1; !q.empty(); level++, size = q.size())
        {
            while (size--)
            {
                int cur = q.front();
                q.pop();

                for (int neighbour : graph[cur])
                {
                    if (neighbour == parent[cur]) continue; // fake cycle

                    if (len[neighbour] == OO)
                    {
                        q.push(neighbour);
                        len[neighbour] = level + 1;
                        parent[neighbour] = cur;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool has_cycle(GRAPH &graph)
    {
        int n = graph.size();
        vector<int> len(n, OO);
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && len[i] == OO) return true;

            if (len[i] == OO && bfs_cycle(graph, i, len , parent)) return true;
        }
        return false;

    }

public:
    bool validTree(int nodes, vector<vector<int>> &edges)
    {
        if (edges.size() != nodes - 1) return false;

        GRAPH graph(nodes);

        for (auto &edge : edges)
        {
            add_undirected_edge(graph, edge[0], edge[1]);
        }

        return !has_cycle(graph);
    }
};
