class Solution {
public:
    void solve(vector<vector<int>>& v, int r, int c, int m, int n) {
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto& d : dirs) {
            int x = r + d[0], y = c + d[1];
            while (x >= 0 && x < m && y >= 0 && y < n && v[x][y] != -1 && v
            [x][y] != 1) {
                if (v[x][y] == 0) v[x][y] = 2;
                x += d[0];
                y += d[1];
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (auto i : g) v[i[0]][i[1]] = 1;
        for (auto i : w) v[i[0]][i[1]] = -1;
        for (auto i : g) solve(v, i[0], i[1], m, n);

        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j] == 0) cnt++;
        return cnt;
    }
};