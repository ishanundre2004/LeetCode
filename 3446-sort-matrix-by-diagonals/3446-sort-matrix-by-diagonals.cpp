class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v;
        v.reserve(n);

        for (int i = n-1; i != 0; --i) {
            v.clear();
            for (int j = 0; i+j != n; ++j) {
                v.push_back(grid[j][i+j]);
            }
            sort(v.begin(), v.end());
            for (int j = 0; i+j != n; ++j) {
                grid[j][i+j] = v[j];
            }
        }

        for (int i = 0; i != n; ++i) {
            v.clear();
            for (int j = 0; i+j != n; ++j) {
                v.push_back(grid[i+j][j]);
            }
            sort(v.begin(), v.end(), greater<int>());
            for (int j = 0; i+j != n; ++j) {
                grid[i+j][j] = v[j];
            }
        }

        return grid;
    }
};