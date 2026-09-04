#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int OO = 2147483647;

int dr[4] { -1, 0, 1, 0 };
int dc[4] { 0, 1, 0, -1 };

bool isvalid(int r, int c, vector<vector<int>> &matrix)
{
	if (r < 0 || r >= (int) matrix.size())
		return false;
	if (c < 0 || c >= (int) matrix[0].size())
		return false;
	return true;
}

struct cell
{
	int r, c;
};

class Solution
{
private:

    void bfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<cell> &startings)
    {
        queue<cell> q;
        for (int i = 0; i < (int)startings.size(); i++)
        {
            q.push(startings[i]);
            visited[startings[i].r][startings[i].c] = true;
        }

        for (int levels = 0, sz = 1; !q.empty(); sz = q.size(), levels++)
        {
            while (sz--)
            {
                int r = q.front().r, c = q.front().c;
                q.pop();

                for (int i  =0; i < 4; i++)
                {
                    int nr = dr[i] + r, nc = dc[i] + c;

                    if (!isvalid(nr, nc, matrix) || visited[nr][nc] || matrix[r][c] > matrix[nr][nc])
                    {
                        continue;
                    }

                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<bool>> ReachablePacific(rows, vector<bool>(cols));
        vector<vector<bool>> ReachableAtlantic(rows, vector<bool>(cols));

        vector<cell> StartingsPacific;
        vector<cell> StartingsAtlantic;

        for (int i = 0; i < cols; i++)
        {
            StartingsPacific.push_back({0, i});
            StartingsAtlantic.push_back({rows - 1, i});
        }

        for (int i = 0; i < rows; i++)
        {
            StartingsPacific.push_back({i, 0});
            StartingsAtlantic.push_back({i, cols-1});
        }

        bfs(heights, ReachablePacific, StartingsPacific);
        bfs(heights, ReachableAtlantic, StartingsAtlantic);

        vector<vector<int>> result;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (ReachablePacific[i][j] && ReachableAtlantic[i][j])
                {
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};