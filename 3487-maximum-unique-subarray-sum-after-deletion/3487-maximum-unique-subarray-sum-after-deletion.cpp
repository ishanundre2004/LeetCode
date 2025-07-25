class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(*max_element(nums.begin(), nums.end()) < 0){
            return *max_element(nums.begin(), nums.end());
        }

        unordered_set<int> s;
        for(auto& it : nums){
            if(it > 0){
                s.insert(it);
            }
        }

        int ans = 0;
        for(auto& it : s){
            ans += it;
        }
        return ans;
    }
};