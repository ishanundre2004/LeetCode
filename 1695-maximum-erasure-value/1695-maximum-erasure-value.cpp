class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int l = 0, h = 0;
        int sum = 0 , currSum = 0;
        while(h < nums.size()){
            while(freq[nums[h]] > 0){
                freq[nums[l]]--;
                currSum -= nums[l];
                l++;
            }

            currSum += nums[h];
            freq[nums[h]]++;
            h++;
            sum = max(sum, currSum);
        }
        return sum;
    }
};