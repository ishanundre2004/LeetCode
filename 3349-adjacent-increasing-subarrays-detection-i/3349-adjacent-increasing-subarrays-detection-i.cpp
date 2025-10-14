class Solution {
public:
    bool isIncreasing(int i, int k, vector<int>& nums){
        for(int j = i; j < i+k-1; j++){
            if(nums[j] >= nums[j+1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i <= n-(2*k); i++){
            if(isIncreasing(i, k, nums) && isIncreasing(i+k, k ,nums)) return true;
        }
        return false;
    }
};