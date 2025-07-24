#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> tree(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> subtree_xor(n);
        vector<int> in(n), out(n), parent(n, -1);
        int time = 0;
        function<void(int, int)> dfs = [&](int u, int par) {
            in[u] = time++;
            subtree_xor[u] = nums[u];
            for (int v : tree[u]) {
                if (v == par) continue;
                parent[v] = u;
                dfs(v, u);
                subtree_xor[u] ^= subtree_xor[v];
            }
            out[u] = time++;
        };
        dfs(0, -1);

        int res = INT_MAX;
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                bool u_in_v = (in[u] > in[v] && out[u] < out[v]);
                bool v_in_u = (in[v] > in[u] && out[v] < out[u]);
                int a, b, c;
                if (u_in_v) {
                    a = subtree_xor[u];
                    b = subtree_xor[v] ^ subtree_xor[u];
                    c = subtree_xor[0] ^ subtree_xor[v];
                } else if (v_in_u) {
                    a = subtree_xor[v];
                    b = subtree_xor[u] ^ subtree_xor[v];
                    c = subtree_xor[0] ^ subtree_xor[u];
                } else {
                    a = subtree_xor[u];
                    b = subtree_xor[v];
                    c = subtree_xor[0] ^ subtree_xor[u] ^ subtree_xor[v];
                }
                int mx = max({a, b, c});
                int mn = min({a, b, c});
                res = min(res, mx - mn);
            }
        }
        return res;
    }
};