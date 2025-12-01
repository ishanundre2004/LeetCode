class Solution {
public:
    long long maxRunTime(int n, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = nums.size() - 1; i >= 0 ; i--){
            if (nums[i] <= total/n) return total/n;
            total -= nums[i];
            n--;
        }
        return  total/n;
    }
};