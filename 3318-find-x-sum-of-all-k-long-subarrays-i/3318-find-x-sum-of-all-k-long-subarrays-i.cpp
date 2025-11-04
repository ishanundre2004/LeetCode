class Solution {
public:
    int solve(int i, int j, int x, vector<int>& nums){
        int sum = 0;
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> freq;
        for(int a = i; a <= j; a++) freq[nums[a]]++;
        for(auto& it : freq) q.push({it.second, it.first});
        while(x-- && !q.empty()) sum += q.top().second * q.top().first, q.pop(); 
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(), m = n-k+1, i= 0;
        vector<int> ans(m);
        while(i < m) ans[i] = solve(i, i+k-1, x, nums), i++;
        return ans;
    }
};