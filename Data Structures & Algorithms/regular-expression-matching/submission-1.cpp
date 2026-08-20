class Solution {
public:
    

    bool func(string& s, string& p, int i, int j,vector<vector<int>>& dp) {
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = (i < s.size() &&
                     (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] =
                func(s, p, i, j + 2,dp) ||
                (match && func(s, p, i + 1, j,dp));
        }

        return dp[i][j] =
            match && func(s, p, i + 1, j + 1,dp);
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return func(s, p, 0, 0,dp);
    }
};