class Solution {
public:
    bool isIncreasing(int i, int k, vector<int>& nums) {
        for (int j = i; j < i + k - 1; j++) {
            if (nums[j] >= nums[j + 1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++) {
            if (isIncreasing(i, k, nums) && isIncreasing(i + k, k, nums))
                return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 1, h = n / 2;
        int ans = 0;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (hasIncreasingSubarrays(nums, m)) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
};
