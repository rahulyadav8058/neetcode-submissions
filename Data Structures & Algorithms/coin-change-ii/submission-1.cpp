class Solution {
   public:
    int func(vector<int>& coins, int ind, int amt, vector<vector<int>>& dp) {
        if (amt == 0) return 1;
        if (ind == coins.size()) {
            return 0;
        }
        if (dp[ind][amt] != -1) return dp[ind][amt];
        int pick = 0;
        if (amt >= coins[ind]) {
            pick = func(coins, ind, amt - coins[ind], dp);
        }
        return dp[ind][amt] = pick + func(coins, ind + 1, amt, dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int amt = 1; amt <= amount; amt++) {
                int notPick = dp[ind + 1][amt];

                int pick = 0;
                if (amt >= coins[ind]) pick = dp[ind][amt - coins[ind]];

                dp[ind][amt] = pick + notPick;
            }
        }

        return dp[0][amount];
    }
};
