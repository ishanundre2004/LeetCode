class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long streak = 0;
        long long cnt = 0;
        for(auto& it : nums){
            if(it == 0){
                streak++;
                cnt+=streak;
            }else{
                streak = 0;
            }

        }
        return cnt;
    }
};