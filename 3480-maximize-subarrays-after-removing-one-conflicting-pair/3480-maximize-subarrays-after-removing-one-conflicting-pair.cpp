class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        unordered_map<int, vector<int>> limits;

        for (const auto& pair : conflictingPairs) {
            int a = pair[0], b = pair[1];
            limits[max(a, b)].push_back(min(a, b));
        }

        long long res = 0;
        vector<int> left = {0, 0};  
        vector<long long> after_removal(n + 1, 0);

        for (int r = 1; r <= n; ++r) {
            for (int l : limits[r]) {
                if (l > left[0]) {
                    left[1] = left[0];
                    left[0] = l;
                } else if (l > left[1]) {
                    left[1] = l;
                }
            }
            res += r - left[0];
            after_removal[left[0]] += (left[0] - left[1]);
        }

        return res + *max_element(after_removal.begin(), after_removal.end());
    }
};