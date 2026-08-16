class Solution {
   public:
    bool func(string s1, string s2, string s3, int i, int j, vector<vector<int>>& dp) {
        int k = i + j;

        if (i == s1.size() && j == s2.size() && k == s3.size()) return true;

        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if (i < s1.size() && s1[i] == s3[k]) {
            ans = func(s1, s2, s3, i + 1, j, dp);
        } 
        
         if (j < s2.size() && s2[j] == s3[k])
            ans = ans || func(s1, s2, s3, i, j + 1, dp);

        
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return func(s1, s2, s3, 0, 0, dp);
    }
};
