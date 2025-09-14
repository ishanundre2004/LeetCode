class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double total = accumulate(nums.begin(), nums.end(), 0.0);
        double avg = total/nums.size();
        unordered_set<int>s(nums.begin(), nums.end());
        int ans = floor(avg) + 1;
        while(s.find(ans) != s.end()){
            
            ans++;
        }
        return ans;
    }
};