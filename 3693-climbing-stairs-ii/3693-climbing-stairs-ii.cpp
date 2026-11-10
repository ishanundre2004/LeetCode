class Solution {
public:
    int solve(int n, vector<int>& c, vector<int>& dp) {
        if (n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        int x = solve(n-1, c, dp) + c[n-1] + 1;
        int y = (n >= 2) ? solve(n-2, c, dp) + c[n-1] + 4 : INT_MAX;
        int z = (n >= 3) ? solve(n-3, c, dp) + c[n-1] + 9 : INT_MAX;

        return dp[n] = min({x, y, z});
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int x = dp[i-1] + costs[i-1] + 1;
            int y = (i >= 2) ? dp[i-2] + costs[i-1] + 4 : INT_MAX;
            int z = (i >= 3) ? dp[i-3] + costs[i-1] + 9 : INT_MAX;

            dp[i] = min({x, y, z});
        }
        return dp[n];
    }
};