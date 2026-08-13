class Solution {
   public:
    int func(int l, int r, vector<int>& nums,vector<vector<int>> &dp) {
        // if(ind == nums.size())return 0;
        if (l > r) return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int temp = 0;
        for (int k = l ; k <= r; k++) {
            temp = max(temp, nums[k] * nums[l - 1] * nums[r + 1] + func(l, k - 1, nums,dp) + func(k+1, r, nums,dp));
        }
        return dp[l][r] = temp;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        
        temp.push_back(1);
        for (auto ele : nums) {
            temp.push_back(ele);
        }
        temp.push_back(1);
        int n = temp.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        
        return func(1, nums.size(), temp,dp);
    }
};
