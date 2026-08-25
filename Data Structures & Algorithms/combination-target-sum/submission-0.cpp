class Solution {
public:
    void func(vector<int>& nums, int target,int ind ,vector<vector<int>>& ans, vector<int>& temp, int sum){
        if(sum>target || ind ==nums.size())return ;
        if(sum == target){ans.push_back(temp);return;}

        func(nums,target,ind+1,ans,temp,sum);

        temp.push_back(nums[ind]);
        func(nums,target,ind,ans,temp,sum + nums[ind]);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(nums,target,0,ans,temp,0);
        return ans;
    }
};
