class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0, j=0; i<n; i++){
            if(nums[i]==key){
                int till =  min(n-1, i+k);
                for(j=max(j, i-k); j<=till; j++) ans.push_back(j);
            }
        }
        return ans;
    }
};