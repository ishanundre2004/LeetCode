class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> r(m, 0); // to track i;
        vector<int> c(n, 0); // to track j;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    r[i]++;
                    c[j]++;
                    cnt++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (r[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && c[j] == 1) {
                        cnt--;
                    }
                }
            }
        }
        return cnt;
    }
};