class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(auto i : nums) sum = (sum+i)%p;
        int tar = sum%p;
        if(tar == 0) return 0;
        int n = nums.size(), pre = 0, ans = n;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        for(int i = 0 ; i < n; i++){
            pre = (pre+ nums[i]) % p;
            int rem = (pre - tar + p) % p;
            if(mpp.count(rem)){
                ans = min(ans, i - mpp[rem]);
            }
            
            mpp[pre] = i;
        }
        return ans == n ? -1 : ans;
    }
};