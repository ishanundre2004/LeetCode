class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int last = nums[0] - k - 1, uniqs = 0;
        for(int i : nums){
            if(i-k > last && ++uniqs) last = i-k;
            else if(last < i+k && ++uniqs) last++;
        }
        return uniqs;
    }
};