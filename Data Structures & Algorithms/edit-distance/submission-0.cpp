class Solution {
public:
    int func(string a , string b,int i, int j,vector<vector<int>>& dp){
        if(i==a.size() && j==b.size()){
            return 0;   
        }
        if(i==a.size()){
            return b.size()-j;
        }
        if(j==b.size()){
            return a.size()-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(a[i]==b[j]){
            return dp[i][j] =func(a,b,i+1,j+1,dp);
        }
        else{
            return dp[i][j] =1+min(func(a,b,i+1,j,dp),min(func(a,b,i+1,j+1,dp),func(a,b,i,j+1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return func(word1,word2,0,0,dp);
    }
};
