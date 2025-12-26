class Solution {
public:
    int bestClosingTime(string s) {
        int cnt = 0;
        for(auto& c : s) if(c == 'Y') cnt++;
        int mini = cnt, idx = 0;

        for(int i = 0; i < s.length(); i++){
            (s[i] == 'Y') ? cnt-- : cnt++;
            if(cnt < mini) {
                mini = cnt;
                idx = i+1;
            } 
        }
        return idx;

    }
};