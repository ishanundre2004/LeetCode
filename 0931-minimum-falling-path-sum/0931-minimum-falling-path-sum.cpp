class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int minSum = 1e9;
        vector<vector<int>> dp(n, (vector<int>(m, -1)));

        for(int i = 0; i < m; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i = n-2; i >=0; i--){
            for(int j= m-1; j >= 0; j--){
                int left = 1e9, right = 1e9, down = 1e9;
                if (j-1 >=0 )  left = dp[i+1][j-1];
                if (j >=0 && j < n )  down = dp[i+1][j];
                if (j+1 < n )  right = dp[i+1][j+1];

                dp[i][j] = matrix[i][j] + min({left, right, down});
            }
        }
        for (int col = 0; col < m; col++) {
            minSum = min(minSum, dp[0][col]);
        }
        return minSum;
    }
};