class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> fact(m + 1, 1), invfact(m + 1, 1);
        for (int i = 1; i <= m; ++i) fact[i] = fact[i-1] * i % MOD;
        auto modpow = [&](long long a, long long e){
            long long r = 1;
            while (e) {
                if (e & 1) r = (r * a) % MOD;
                a = (a * a) % MOD;
                e >>= 1;
            }
            return r;
        };
        invfact[m] = modpow(fact[m], MOD - 2);
        for (int i = m; i >= 1; --i) invfact[i-1] = invfact[i] * i % MOD;
        vector<vector<long long>> powNum(n, vector<long long>(m + 1, 1));
        for (int j = 0; j < n; ++j) {
            for (int c = 1; c <= m; ++c)
                powNum[j][c] = powNum[j][c-1] * (nums[j] % MOD) % MOD;
        }

        int C = m + 1;
        int O = k + 1;
        int U = m + 1;
        auto idx = [&](int carry, int ones, int used){
            return (carry * O + ones) * U + used;
        };
        vector<long long> dp(C * O * U, 0), dp2(C * O * U, 0);
        dp[idx(0,0,0)] = 1;

        for (int pos = 0; pos < n; ++pos) {
            fill(dp2.begin(), dp2.end(), 0);
            for (int carry = 0; carry <= m; ++carry) {
                for (int ones = 0; ones <= k; ++ones) {
                    for (int used = 0; used <= m; ++used) {
                        long long cur = dp[idx(carry, ones, used)];
                        if (!cur) continue;
                        int rem = m - used;
                        for (int c = 0; c <= rem; ++c) {
                            int total = c + carry;
                            int bit = total & 1;
                            int nextCarry = total >> 1;
                            int nextOnes = ones + bit;
                            if (nextOnes > k) continue;
                            long long add = cur;
                            add = add * powNum[pos][c] % MOD;
                            add = add * invfact[c] % MOD;
                            long long &ref = dp2[idx(nextCarry, nextOnes, used + c)];
                            ref = (ref + add) % MOD;
                        }
                    }
                }
            }
            dp.swap(dp2);
        }
        long long ans = 0;
        for (int carry = 0; carry <= m; ++carry) {
            for (int ones = 0; ones <= k; ++ones) {
                long long val = dp[idx(carry, ones, m)];
                if (!val) continue;
                int finalOnes = ones + __builtin_popcount((unsigned)carry);
                if (finalOnes == k) {
                    val = val * fact[m] % MOD;
                    ans = (ans + val) % MOD;
                }
            }
        }
        return (int)ans;
    }
};