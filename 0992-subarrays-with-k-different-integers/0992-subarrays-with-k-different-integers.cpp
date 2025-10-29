class Solution {
public:
    int solve(vector<int>& nums, int k){
        int l = 0 , cnt = 0, n = nums.size();
        unordered_map<int, int> freq;
        for(int r = 0 ; r < n; r++){
            freq[nums[r]]++;
            while(freq.size() > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};