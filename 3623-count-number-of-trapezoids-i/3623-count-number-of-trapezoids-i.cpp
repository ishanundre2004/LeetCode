class Solution {
public:
    long long mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mpp;
        vector<long long> pre;
        long long sum = 0, ans = 0, prev = 0;
        for (auto& point : points) mpp[point[1]]++;
        for (auto& it : mpp) {
            long long n = it.second;
            if (n >= 2) {
                long long x = ((n * (n - 1)) / 2) % mod;
                pre.push_back(sum += x);
            }
        }
        for (auto& it : pre) ans = (ans + ((it - prev) * (sum - it)) % mod) % mod, prev = it;
        return ans % mod;
    }
};
