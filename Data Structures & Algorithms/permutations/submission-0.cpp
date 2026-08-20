class Solution {
public:
    void func(vector<int>& nums, int ind,vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i =ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            func(nums,ind+1,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        func(nums,0,ans);
        return ans;
    }
};
