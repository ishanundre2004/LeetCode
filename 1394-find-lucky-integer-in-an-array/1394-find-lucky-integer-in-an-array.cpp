class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto& it: arr) freq[it]++;
        int ans = -1;
        for(auto& it : freq){
            if(it.first == it.second) ans = max(ans, it.first);
        }
        return ans;

    }
};