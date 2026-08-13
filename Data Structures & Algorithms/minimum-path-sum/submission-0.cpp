class Solution {
public:
    int func(vector<vector<int>>& grid,int i ,int j,vector<vector<int>>& dp){
        if(i==grid.size() || j==grid[0].size())return INT_MAX;
        if(i==grid.size()-1 && j==grid[0].size()-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = grid[i][j] + min(func(grid,i+1,j,dp), func(grid,i,j+1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp (m,vector<int>(n,-1));
        return func(grid,0,0,dp);
    }
};