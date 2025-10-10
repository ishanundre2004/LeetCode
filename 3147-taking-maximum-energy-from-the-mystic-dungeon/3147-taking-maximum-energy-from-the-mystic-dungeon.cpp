class Solution {
public:
    int maximumEnergy(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n);

        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n)
                v[i] = nums[i] + v[i + k];
            else
                v[i] = nums[i];
        }

        int ans = INT_MIN;
        for(auto& it: v){
            ans = max(ans, it);
        }
        return ans;
    }
};
