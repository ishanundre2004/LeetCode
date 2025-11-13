class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0, ans = 0;
        for(int i = 0; i < s.length()-1; i++) {
            if(s[i] == '1'){
                cnt++;
                ans += (s[i+1] == '0') ? cnt : 0;
            }
        }
        return ans;
    }
};