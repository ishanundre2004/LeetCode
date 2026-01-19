class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // Prefix sum with padding
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        auto can = [&](int len) {
            for (int i = len; i <= m; i++) {
                for (int j = len; j <= n; j++) {
                    int sum = pre[i][j]
                            - pre[i - len][j]
                            - pre[i][j - len]
                            + pre[i - len][j - len];
                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        int l = 1, h = min(m, n), ans = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (can(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};
