class Solution {
public:
    int func(vector<int>& coins,int ind,int amt,vector<vector<int>>& dp){
        if(amt ==0)return 1;
        if(ind==coins.size()){return 0;}
        if(dp[ind][amt]!=-1)return dp[ind][amt];
        int pick = 0;
        if(amt>=coins[ind]){
            pick = func(coins,ind,amt-coins[ind],dp);
        }
        return dp[ind][amt] =pick + func(coins,ind+1,amt,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return func(coins,0,amount,dp);
    }
};
