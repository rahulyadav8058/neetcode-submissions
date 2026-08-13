class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long>suffix(n,1);
        long long temp=1;
        for(int i = n-1;i>=0;i--){
            suffix[i] = temp;
            temp *= nums[i];     
        }
        vector<int>ans(n);
        long long pre =1;
        for(int i =0;i<n;i++){
            ans[i] = suffix[i]*pre;
            pre *= nums[i];
        }
        return ans;
    }
};
