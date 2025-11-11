class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));;
        for(auto& i: strs){
            int zero =0,one = 0;
            for(auto& j : i) (j == '0') ? zero++ : one++;
            v.push_back({zero, one});
        }
        for(auto& it : v)
            for(int i = m; i >= it[0]; i--) 
                for(int j = n; j >= it[1]; j--) dp[i][j] = max(dp[i][j], 1+dp[i-it[0]][j-it[1]]);
        return dp[m][n];
    }
};