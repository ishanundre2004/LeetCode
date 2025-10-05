class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    int n, m;


    bool valid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    void dfs(int row, int col, vector<vector<int>>& ocean,
             vector<vector<int>>& heights) {
        ocean[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (valid(nrow, ncol) && !ocean[nrow][ncol] &&
                (heights[nrow][ncol] >= heights[row][col])) {
                dfs(nrow, ncol, ocean, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int i = 0; i < m; ++i) {
            if (!pacific[0][i]) {
                dfs(0, i, pacific, heights);
            }
            if (!atlantic[n - 1][i]) {
                dfs(n - 1, i, atlantic, heights);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!pacific[i][0]) {
                dfs(i, 0, pacific, heights);
            }
            if (!atlantic[i][m - 1]) {
                dfs(i, m - 1, atlantic, heights);
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};