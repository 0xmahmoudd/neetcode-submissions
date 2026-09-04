#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
#include<unordered_set>
#include<queue>
using namespace std;

struct node
{
    int r,  c;
};

class Solution
{
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(int r, int c, vector<vector<int>> &matrix)
    {        if (r < 0 || r >= matrix.size()) return false;
        if (c < 0 || c >= matrix[0].size()) return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (!is_valid(r, c, grid) || grid[r][c] == 0 || visited[r][c]) return;

        visited[r][c] = true;

        for (int i = 0; i < 4; i++)
        {
            dfs(r + dr[i], c + dc[i], grid, visited);
        }
    }

    int bfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        queue<node> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(visited[i][j]) q.push({i, j});
            }
        }

        for (int level = 0; !q.empty(); level++)
        {
            int sz = q.size();
            while (sz--)
            {
                node curr = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nr = curr.r + dr[k];
                    int nc = curr.c + dc[k];
                    if (!is_valid(nr, nc, grid) || visited[nr][nc]) continue;
                    if (grid[nr][nc] == 1) return level;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return 0;
    }

    
public:

    int shortestBridge(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool> (c, false));

        bool found = false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid, visited);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        return bfs(0, 0, grid, visited);
    }
    
};