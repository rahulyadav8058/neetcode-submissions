class Solution {
public:
    int func(vector<vector<int>>& matrix, int i, int j,
             vector<vector<int>>& dp) {

        int n = matrix.size();
        int m = matrix[0].size();

        if (i >= n || j >= m)
            return 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        int temp = 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        for (int k = 0; k < 4; k++) {

            int nr = i + dx[k];
            int nc = j + dy[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                matrix[nr][nc] > matrix[i][j]) {

                temp = max(temp,
                           1 + func(matrix, nr, nc, dp));
            }
        }

        return dp[i][j] = temp;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m  = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (dp[i][j] == -1)
                    ans = max(ans, func(matrix, i, j, dp));
            }
        }

        return ans;
    }
};