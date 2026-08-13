class Solution {
   public:
    bool func(vector<int>& nums, vector<bool>& used, int start, int sum, int target, int k) {
        if (k == 1) return true;

        if (sum == target) return func(nums, used, 0, 0, target, k - 1);

        for (int i = start; i < nums.size(); i++) {
            if (used[i]) continue;

            if (sum + nums[i] > target) continue;

            used[i] = true;

            if (func(nums, used, i + 1, sum + nums[i], target, k)) return true;

            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;

        for (int x : nums) total += x;

        if (total % k != 0) return false;

        int target = total / k;

        vector<bool> used(nums.size(), false);

        return func(nums, used, 0, 0, target, k);
    }
};