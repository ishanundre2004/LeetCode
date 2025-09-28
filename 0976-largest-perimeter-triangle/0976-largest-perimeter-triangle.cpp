class Solution {
public:
    int isTriangle(int a, int b, int c){
        if(a+b <= c) return false;
        else if(a+c <= b) return false;
        else if(b+c <= a) return false;
        return true;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i <nums.size()-2; i++){
            if(isTriangle(nums[i], nums[i+1], nums[i+2])) {
                ans = max(ans,nums[i] + nums[i+1] +nums[i+2]);
            }
        }
        return ans;
    }
};