class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini =1;
        int maxi = 1;
        int ans =nums[0];
        for(int i=0;i<nums.size();i++){
            int temp = maxi *nums[i];
            maxi = max(maxi*nums[i],max(nums[i],mini*nums[i]));
            mini = min(nums[i],min(mini*nums[i],temp));
            ans= max(ans,maxi);
        }
        return ans;
    }
};
