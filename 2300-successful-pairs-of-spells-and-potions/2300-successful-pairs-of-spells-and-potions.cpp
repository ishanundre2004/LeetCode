class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            long long x = (success + spells[i] - 1) / spells[i];
            if (x > potions[m - 1])
                ans[i] = 0;
            else
                ans[i] = m - (lower_bound(potions.begin(), potions.end(), x) - potions.begin());

        }
        return ans;
    }
};
