class Solution:
    def func(self, nums: list[int], ind: int, n: int, dp: list[int]) -> int:
        if ind >= n:
            return 0

        if dp[ind] != -1:
            return dp[ind]

        pick = nums[ind] + self.func(nums, ind + 2, n, dp)
        not_pick = self.func(nums, ind + 1, n, dp)

        dp[ind] = max(pick, not_pick)
        return dp[ind]

    def rob(self, nums: list[int]) -> int:
        n = len(nums)

        if n == 1:
            return nums[0]

        # Case 1: Exclude the last house
        dp1 = [-1] * n
        case1 = self.func(nums, 0, n - 1, dp1)

        # Case 2: Exclude the first house
        dp2 = [-1] * n
        case2 = self.func(nums, 1, n, dp2)

        return max(case1, case2)