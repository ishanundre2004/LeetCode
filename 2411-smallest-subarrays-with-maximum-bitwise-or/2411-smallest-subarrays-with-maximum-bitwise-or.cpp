class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 0; i < n; ++i) {
            int curr = nums[i];
            int prev = i - 1;

            while (prev >= 0 && (nums[prev] | curr) != nums[prev]) {
                res[prev] = i - prev + 1;
                nums[prev] |= curr;
                --prev;
            }
        }

        return res;
    }
};