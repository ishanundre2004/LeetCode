class Solution {
public:
    void helper(vector<int>& arr, unordered_set<int>& x, int curr_or, int i, unordered_map<int, unordered_set<int>>& dp){
        if(i  == arr.size()) return;
        
        curr_or |= arr[i];
        if(dp[i].count(curr_or)) return;
        dp[i].insert(curr_or);
        x.insert(curr_or);
        helper(arr, x, curr_or, i+1, dp);
    }
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> x;
        unordered_map<int, unordered_set<int>> dp;
        for(int i = 0; i < arr.size(); i++){
            helper(arr, x, 0, i, dp);
        }
        return x.size();
    }
};