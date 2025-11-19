class Solution {
public:
    int findFinalValue(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(auto& it : nums) if(it == k) k*=2;
        return k;
    }
};