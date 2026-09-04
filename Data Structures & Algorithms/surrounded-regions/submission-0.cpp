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

    void dfs(int r, int c, vector<vector<char>> &grid)
    {
        if (!is_valid(r,c,grid) || grid[r][c] != 'O') return;

        grid[r][c] = 'S';

        for (int i = 0; i < 4; i++)
        {
            dfs(dr[i] + r, dc[i] + c, grid);
        }
    }

public:
    void solve(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    && grid[r][c] == 'O')
                {
                    dfs(r, c, grid);
                }
            }
        }

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == 'O') grid[r][c] = 'X';
                else if (grid[r][c] == 'S') grid[r][c] = 'O';
            }
        }
    }
};