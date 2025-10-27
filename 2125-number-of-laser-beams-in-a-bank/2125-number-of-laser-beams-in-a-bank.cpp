class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(auto& it  : bank){
            int cur = 0;
            for(auto& bin : it){
                if(bin == '1') cur++;
            }
            if(cur!=0){
                ans += (prev*cur);
                prev = cur;
            }
        }
        return ans;
    }
};