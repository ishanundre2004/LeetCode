class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i =0 ; i< n-1; i++){
            if(nums[i+1] < nums[i]) return i;
        }
        return n-1;
    }
};