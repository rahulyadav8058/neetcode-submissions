class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            int cost = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy = {0, 0, 1, -1};

            for (int w = 0; w < 4; w++) {
                int nr = dx[w] + i;
                int nc = dy[w] + j;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != -1 &&
                    grid[nr][nc] > cost + 1) {
                    grid[nr][nc] = cost + 1;
                    q.push({cost+1, {nr, nc}});
                }
            }
        }
    }
};
