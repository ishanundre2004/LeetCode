class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxFreq = INT_MIN;
        for(auto& it : nums){
            mpp[it]++;
            maxFreq = max(maxFreq, mpp[it]);
        }
        int cnt = 0;
        for(auto& it : mpp){
            if(it.second == maxFreq){
                cnt += it.second;
            }
        }
        return cnt;
    }
};