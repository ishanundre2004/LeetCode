class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s (nums.begin(), nums.end());
        int i = k;
        while(s.count(i)) i+=k;
        return i;
    }
};