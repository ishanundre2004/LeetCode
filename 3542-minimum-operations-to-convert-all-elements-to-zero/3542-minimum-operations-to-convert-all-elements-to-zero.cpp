class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        stack<int> st;
        for(int i = 0 ; i < nums.size(); i++){
            while(!st.empty() && st.top() > nums[i]) st.pop();
            if(nums[i] == 0) continue;
            if(st.empty() || st.top() < nums[i]) st.push(nums[i]), cnt++;
        }
        return cnt;
    }
};