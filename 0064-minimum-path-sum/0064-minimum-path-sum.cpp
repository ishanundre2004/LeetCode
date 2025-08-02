class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp){
        if(i == n-1 && j == m-1 ){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int right = INT_MAX, down = INT_MAX;
        if(j < m-1) right = grid[i][j] + helper(i, j+1, grid, n, m, dp);
        if(i < n-1) down = grid[i][j] + helper(i+1, j, grid, n, m, dp);

        return dp[i][j] = min(right, down); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(0, 0, grid, n, m, dp);
    }
};