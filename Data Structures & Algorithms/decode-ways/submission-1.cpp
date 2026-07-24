class Solution {
   public:
    int func(string s, int ind, vector<int>& dp) {
        if (ind == s.size()) return 1;
        if (s[ind] == '0') return 0;
        if (dp[ind] != -1) return dp[ind];

        int ans = func(s, ind + 1, dp);
        if (ind + 1 < s.size()) {
            if ((s[ind] - '0') * 10 + s[ind + 1] - '0' <= 26) {
                ans += func(s, ind + 2, dp);
            }
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        // string temp = "";
        vector<int> dp(s.size(), -1);
        return func(s, 0, dp);
    }
};
