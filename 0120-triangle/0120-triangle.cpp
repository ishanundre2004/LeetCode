class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        if(i == triangle.size()-1){
            return triangle[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];
        int down = helper(triangle, i+1, j, dp) + triangle[i][j];
        int diag = helper(triangle, i+1, j+1, dp) + triangle[i][j];

        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i = 0; i < m; i++){
            dp[n-1][i] = triangle[n-1][i] ;
        }

        for(int i = n-2; i >= 0; i--){
            int k= triangle[i].size()-1;
            for(int j = k ; j>=0; j--){
                int down = 1e9, diag = 1e9;
                down = dp[i+1][j];
                diag = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
        
        return dp[0][0];
    }
};