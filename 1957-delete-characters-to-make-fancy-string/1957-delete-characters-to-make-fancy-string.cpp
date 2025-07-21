class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1;
        string ans  = "";
        ans.push_back(s[0]);
        for(int i = 1; i<s.length(); i++){
            if(s[i] == s[i-1]){
                cnt++;
                if(cnt < 3) ans += s[i];
            }else{
                cnt = 1;
                ans += s[i];
            }
        }
        return ans;
    }
};