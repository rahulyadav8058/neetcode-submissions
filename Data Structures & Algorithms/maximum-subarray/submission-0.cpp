class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans =INT_MIN;
        int maxi =0;
        
        for(int i=0;i<nums.size();i++){

            maxi = max({nums[i],nums[i]+maxi});
            ans = max(ans,maxi);
        }
          return ans;
    }
  
};
