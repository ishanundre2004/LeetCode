class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid) {
        unordered_set<int> seen;

        for (int r = i; r < i + 3; r++) {
            for (int c = j; c < j + 3; c++) {
                if (grid[r][c] < 1 || grid[r][c] > 9) return false;
                seen.insert(grid[r][c]);
            }
        }
        if (seen.size() != 9) return false;
        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        for (int r = i; r < i + 3; r++) {
            int s = 0;
            for (int c = j; c < j + 3; c++)
                s += grid[r][c];
            if (s != sum) return false;
        }
        for (int c = j; c < j + 3; c++) {
            int s = 0;
            for (int r = i; r < i + 3; r++)
                s += grid[r][c];
            if (s != sum) return false;
        }
        if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != sum) return false;
        if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != sum) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                if (check(i, j, grid)) cnt++;
            }
        }
        return cnt;
    }
};
