class Solution {
   public:
    void func(vector<int>& nums, int ind, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int j = ind; j < nums.size(); j++) {
            if(j>ind && nums[j] == nums[j-1])continue;
            temp.push_back(nums[j]);
            func(nums, j+1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(nums, 0, temp, ans);
        return ans;
    }
};
