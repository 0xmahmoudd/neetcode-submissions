#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
#include<queue>
using namespace std;

struct node
{
    int r, c;
};



class Solution
{
private:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(int r, int c, vector<vector<int>> &grid)
    {
        if (r < 0 || r >= grid.size()) return false;
        if (c < 0 || c >= grid[0].size()) return false;
        return true;
    }

    int bfs(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<node> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        int ans = 0;

        for (int level = 0; !q.empty(); level++)
        {
            int sz = q.size();
            while (sz--)
            {
                node cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nr = cur.r + dr[i];
                    int nc = cur.c + dc[i];

                    if (!is_valid(nr, nc, grid) || grid[nr][nc] != 1) continue;

                    ans = level + 1;

                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1) return -1;
            }
        }
        
        return ans;
    }

public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        return bfs(grid);
    }
};

