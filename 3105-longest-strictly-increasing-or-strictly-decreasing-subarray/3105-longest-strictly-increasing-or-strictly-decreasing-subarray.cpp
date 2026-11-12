class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cntInc = 1, cntDec = 1, maxi = 1;
        for (int i = 1; i < nums.size(); i++) {
            cntInc = nums[i] > nums[i - 1] ? cntInc + 1 : 1;
            cntDec = nums[i] < nums[i - 1] ? cntDec + 1 : 1;
            maxi = max({maxi, cntInc, cntDec});
        }
        return maxi;
    }
};