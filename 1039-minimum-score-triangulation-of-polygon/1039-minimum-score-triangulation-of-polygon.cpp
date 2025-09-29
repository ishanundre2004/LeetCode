class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (j - i < 2)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int x = nums[i] * nums[j] * nums[k] + solve(k, j, nums, dp) +
                    solve(i, k, nums, dp);
            mini = min(mini, x);
        }
        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, values, dp);
    }
};