class Solution {
public:
    int helper(int x, vector<int> nums, int n){
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] != x){
                nums[i] = -1 * nums[i];
                nums[i+1] = -1 * nums[i+1];
                cnt++;
            }
        }
        return (nums[n-1] == x)? cnt : INT_MAX; 
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt1 = helper(1, nums, n);
        int cnt2 = helper(-1, nums, n);
        return cnt1 <= k || cnt2 <= k;
    }
};