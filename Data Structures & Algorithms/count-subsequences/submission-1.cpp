class Solution {
   public:
    int func(string s, string t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = func(s, t, i + 1, j, dp);
        if (s[i] == t[j]) {
            res += func(s, t, i + 1, j + 1, dp);
        }
        return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int res = dp[i + 1][j];
                if (s[i] == t[j]) {
                    res += dp[i+1][j+1];
                }
                dp[i][j] = res;
            }
        }
        return dp[0][0];
        // return func(s, t, 0, 0, dp);
    }
};
