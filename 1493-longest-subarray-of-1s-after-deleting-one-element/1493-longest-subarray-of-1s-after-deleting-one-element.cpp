class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0, ct0=0, total=0, mx=0;
        while(j<nums.size()){
            if(nums[j]==0){
                ct0++;
                while(ct0>1){
                    if(nums[i]==0) ct0--;
                    else total--;
                    i++;
                }
            }
            else{
                total++;
                mx=max(mx, total);
            }
            j++;
        }
        if(mx==nums.size()) return --mx;
        return mx;
    }
};