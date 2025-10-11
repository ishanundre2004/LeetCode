class Solution {
public:
    long long solve(int i, vector<int>& nums, vector<int>& freq,
                    vector<long long>& dp) {
        if (i == 0)
            return 1LL * nums[0] * freq[0];
        if (i < 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        auto it = lower_bound(nums.begin(), nums.end(), nums[i] - 2);
        int ind = -1;
        if (it != nums.begin()) {
            --it;
            ind = it - nums.begin();
        }

        long long notake = solve(i - 1, nums, freq, dp);

        long long take = nums[i] * freq[i] + solve(ind, nums, freq, dp);

        return dp[i] = max(notake, take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mpp;
        for (auto& it : power)
            mpp[it]++;
        vector<int> nums;
        vector<int> freq;
        for (auto& it : mpp) {
            nums.push_back(it.first);
            freq.push_back(it.second);
        }
        int n = nums.size();
        vector<long long> dp(n, -1);
        dp[0] = 1LL * nums[0] * freq[0];

        for (int i = 1; i < n; i++) {
            auto it = lower_bound(nums.begin(), nums.end(), nums[i] - 2);
            int ind = -1;
            if (it != nums.begin()) {
                --it;
                ind = it - nums.begin();
            }
            long long notake = dp[i-1];
            long long take = 1LL * nums[i] * freq[i];

            if(ind >= 0){
                take += dp[ind];
            }

            dp[i] = max(take, notake);
        }
        return dp[n-1];
    }
};