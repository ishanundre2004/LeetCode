class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 1, l = 0;
        sort(nums.begin(), nums.end());
        for(int r = 0;  r < n; r++){
            if(nums[r] > nums[l]*k) l++;
            maxLen = max(maxLen, r-l+1); 
        }
        return n - maxLen;
    }
};