class Solution {
private:
    #define all(v) v.begin(), v.end()
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), ans = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<m; i++) {
            bool ok = false;
            for(int j=1; j<n; j++) {
                if(!vis[j] && strs[j][i] < strs[j-1][i]) {
                    ok = true; break;
                }
            }
            if(ok) {
                ans++;
            } else {
                for(int j=1; j<n; j++) {
                    if(!vis[j] && strs[j][i] > strs[j-1][i]) {
                        vis[j] = 1;
                    }
                }
            }
        }
        return ans;
    }
};