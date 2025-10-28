class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), l = 0, ans = 0;
        for(auto& it : nums){
            int r = sum - l - it;
            if(it == 0){
                if(l == r) ans +=2;
                if(l == r-1 || r == l-1) ans++;
            }
            l+=it;
        }
        return ans;
    }
};