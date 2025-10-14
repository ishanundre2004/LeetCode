class Solution {
public:
    

    bool hasIncreasingSubarrays(vector<int>& nums, vector<int>& v, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++) {
            if (v[i] >= k && v[i + k] >= k)
                return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> v(n);
        v[n-1] = 1;
        for(int i = n-2; i >=0 ; i--){
            if(nums[i+1] > nums[i]) v[i] = v[i+1] + 1;
            else v[i] = 1;
        }

        int l = 1, h = n / 2;
        int ans = 0;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (hasIncreasingSubarrays(nums, v, m)) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
};
