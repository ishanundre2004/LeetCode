class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;  
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int temp = nums[i];
            while(!st.empty() && gcd(temp, st.top()) > 1){
                int x = st.top();
                st.pop();
                temp = lcm(temp, x);
            }
            st.push(temp);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());  
        return ans;
    }
};
