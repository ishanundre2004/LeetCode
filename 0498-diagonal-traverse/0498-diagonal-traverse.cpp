class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        int v = -1, h = 1, i = 0, j = 0;

        while (i != n - 1 || j != m - 1) {

            while (i >= 0 && i < n && j >= 0 && j < m) {
                ans.push_back(mat[i][j]);
                i += v;
                j += h;
            }

            if (i == n) {
                i = n - 1;
                j = j + 2;
            } else if (j == m) {
                j = m - 1;
                i = i + 2;
            } else {
                if (i == -1)
                    i = 0;
                if (j == -1)
                    j = 0;
            }

            v *= -1;
            h *= -1;
        }

        ans.push_back(mat[i][j]);
        return ans;
    }
};