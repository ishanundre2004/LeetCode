class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = nums[0];
        for(int i = 0; i<nums.size(); i++){
            maxNum = max(maxNum, nums[i]);
        }
        int count = 0;
        int len = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == maxNum) {
                count++;
                len = max(len, count);
            }else {
                count = 0;
            }
        }
        return len;

    }
};