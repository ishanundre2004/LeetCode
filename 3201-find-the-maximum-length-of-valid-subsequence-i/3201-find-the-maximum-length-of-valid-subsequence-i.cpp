class Solution {
public:
    int solve(vector<int>& nums, int i, int even, vector<vector<int>>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i][even] != -1) return dp[i][even];

        int take = 0;
        if ((nums[i] % 2 == 0 && even == 0) || (nums[i] % 2 == 1 && even == 1)) {
            take = 1 + solve(nums, i + 1, nums[i] % 2 == 0 ? 1 : 0, dp);
        }

        int notake = solve(nums, i + 1, even, dp);

        return dp[i][even] = max(take, notake);
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));

        int ans = max(solve(nums, 0, 0, dp), solve(nums, 0, 1, dp));

        int even = 0, odd = 0;
        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        int max_count = max(even, odd);
        return max(ans, max_count);
    }
};
