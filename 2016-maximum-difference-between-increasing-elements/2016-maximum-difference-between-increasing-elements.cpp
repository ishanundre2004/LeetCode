class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int n = nums.size();
        int rightMax = nums[n-1];
        for(int i = n-1 ; i >=0 ; i--){
            if(nums[i] < rightMax) diff = max(diff, rightMax - nums[i]);
            rightMax = max(rightMax, nums[i]);
        }
        
        return diff;
    }
};