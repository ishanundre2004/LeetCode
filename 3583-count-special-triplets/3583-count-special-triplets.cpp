class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int cnt = 0;

        unordered_map<int, int> next , prev;

        for(auto &it: nums) next[it]++;

        for(int i = 0; i < nums.size() ;i++){
            next[nums[i]]--;

            int x = nums[i] * 2;

            if(next.count(x) && prev.count(x)){
                cnt = (cnt + 1LL * prev[x] * next[x] % MOD) % MOD;
            }

            prev[nums[i]]++;
        }
        // 
// for (int j = 1; j < nums.size(); j++) {
        //     int x = nums[j] * 2;
        //     int prev = 0, next = 0;

        //     for (int i = 0; i < j; i++) {
        //         if (nums[i] == x) prev++;
        //     }

        //     for (int k = j + 1; k < nums.size(); k++) {
        //         if (nums[k] == x) next++;
        //     }

            
        // }
        return cnt;
    }
};
