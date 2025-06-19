class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 1, mx = nums[0];
        int cnt = 1;
        while(i < n){
            if((nums[i] - mx) > k){
                cnt++;
                mx =  nums[i];
            }
            i++;
        }
        return cnt;
    }
};