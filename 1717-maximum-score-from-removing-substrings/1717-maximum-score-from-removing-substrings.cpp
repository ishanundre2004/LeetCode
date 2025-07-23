class Solution {
public:
    int helper(string& s, int first, int second, char top, char curr){
        stack<char> st;
        int score = 0;
        for(int i = 0; i<s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.top() == top && s[i] == curr){
                    score+=first;
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        s.clear();
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        for(int i = 0; i <s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.top() == curr && s[i] == top){
                    score += second;
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        return score;

    }
    int maximumGain(string s, int x, int y) {
        int ans;
        if(x >= y){
            ans = helper(s, x, y, 'a', 'b');
        }else{
            ans = helper(s, y, x, 'b', 'a');
        }
        return ans;
    }
};