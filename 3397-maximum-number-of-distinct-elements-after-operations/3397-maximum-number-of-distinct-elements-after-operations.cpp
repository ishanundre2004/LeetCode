class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int h = nums[n-1]+k;
        int l = nums[0]-k;
        return min(h-l+1, n);
    }
};