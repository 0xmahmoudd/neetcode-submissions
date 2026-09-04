class Solution {
public:
    int n, m;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    bool isValid(int r, int c) {
        return ((r >= 0 && r < n) && (c >= 0 && c < m));
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int currTime = 0;
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            int currRottenOranges = q.size();
            currTime++;
            while (currRottenOranges--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newRow = r + row[i];
                    int newCol = c + col[i];
                    if (isValid(newRow, newCol) &&
                        (grid[newRow][newCol] == 1)) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return currTime == 0 ? 0 : currTime - 1;
    }
};