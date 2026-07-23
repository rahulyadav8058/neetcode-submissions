class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        if(n<2)return true;
        int ans=0;
        for(int i=0;i<n;i++){
            if(ans<i){return false;}
            ans = max(ans,nums[i]+i);
            if(ans>=n-1)return true;
        }
        return false;
    }
};
