class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = 0;
        sum+=nums[0];
        
        std::vector<int> sorted(nums.begin()+1, nums.end());
        std::sort(sorted.begin(), sorted.end());
        
        sum+=sorted[0];
        sum+=sorted[1];
        return sum;
    }
};