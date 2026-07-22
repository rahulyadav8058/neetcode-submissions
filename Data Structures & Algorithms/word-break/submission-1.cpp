class Solution {
public:
    bool func(string s,int ind, int start,unordered_map<string,bool>& hash,vector<vector<int>>& dp){
        if(ind==s.size()){
            if(hash.find(s.substr(start,ind-start)) == hash.end()){
            return false;
        }
        return true;
        }
        if(dp[ind][start]!=-1)return dp[ind][start];

        if(hash.find(s.substr(start,ind-start)) == hash.end()){
            return dp[ind][start] =func(s,ind+1,start,hash,dp);
        }
        else{
            return dp[ind][start] =func(s,ind+1,start,hash,dp) || func(s,ind+1,ind,hash,dp);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>hash ;
        int n = s.size();
        for(int i=0;i<wordDict.size();i++){
            hash[wordDict[i]] = true;
        }
        string temp="";

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(s,0,0,hash,dp);

    }
};
