#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
using namespace std;

class Solution
{
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(int r, int c, vector<vector<char>> &grid)
    {
        if (r < 0 || r >= grid.size()) return false;
        if (c < 0 || c >= grid[0].size()) return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        if (!is_valid(r, c, grid) || grid[r][c] == '0' || visited[r][c]) return;

        visited[r][c] = true;
        
        for (int i = 0; i < 4; i++)
        {
            dfs(dr[i]+r, dc[i]+c, grid, visited);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    ans++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return ans;
    }
};
