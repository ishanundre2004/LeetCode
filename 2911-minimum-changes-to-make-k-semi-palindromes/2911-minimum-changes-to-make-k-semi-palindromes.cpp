class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();

        vector<vector<int>> cost(n, vector<int>(n, -1));
        for (int len = 2; len <= n; len++) {
            for (int st = 0; st + len <= n; st++) {
                int en = st + len - 1;
                cost[st][en] = INT_MAX;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int changes = 0;
                    for (int offset = 0; offset < d; offset++) {
                        int l = st + offset;
                        int r = st + offset + len - d;
                        while (l < r) {
                            if (s[l] != s[r])
                                changes++;
                            l += d;
                            r -= d;
                        }
                    }
                    cost[st][en] = min(cost[st][en], changes);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));

        dp[0][0] = 0;

        for (int i = 2; i <= n; i++) {
            for (int parts = 1; parts <= k; parts++) {
                for (int prev = i - 2; prev >= 2 * (parts - 1); prev--) {
                    dp[i][parts] = min(dp[i][parts], dp[prev][parts - 1] + cost[prev][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};