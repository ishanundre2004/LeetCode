class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        vector<int> ans;
        ans.push_back(nums[0]);
        k--;
        for(int i = 1; i < nums.size(); i++){
            if(k == 0) break;
            if(nums[i] != ans.back()){
                ans.push_back(nums[i]);
                k--;
            }
        }
        return ans;
    }
};