// https://neetcode.io/problems/islands-and-treasure
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int OO = 2147483647;	// A big value expressing infinity

// Delta for: up, right, down, left
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
    void bfs(vector<vector<int>>& matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        queue<cell> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        for (int levels = 0, sz = q.size(); !q.empty(); sz = q.size(), levels++)
        {
            while (sz--)
            {
                int r = q.front().r, c= q.front().c;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i], nc = c + dc[i];

                    if (!isvalid(nr, nc, matrix) || visited[nr][nc] || matrix[nr][nc] == -1) continue;

                    if (matrix[nr][nc] == OO)
                    {
                        matrix[nr][nc] = levels+1;
                    }

                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid)
    {
        bfs(grid);
    }
};
