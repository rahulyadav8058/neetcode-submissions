class Solution {
public:
    int func(int ind, vector<int>& nums, int tot,
             int target, int offset,
             vector<vector<int>>& dp) {

        if (ind == nums.size()) {
            return tot == target ? 1 : 0;
        }

        int idx = tot + offset;

        if (dp[ind][idx] != -1)
            return dp[ind][idx];

        int add = func(ind + 1, nums,
                       tot + nums[ind],
                       target, offset, dp);

        int subtract = func(ind + 1, nums,
                            tot - nums[ind],
                            target, offset, dp);

        return dp[ind][idx] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;

        for (auto ele : nums)
            total += abs(ele);

        int offset = total;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(2 * total + 1, -1)
        );

        return func(0, nums, 0, target, offset, dp);
    }
};