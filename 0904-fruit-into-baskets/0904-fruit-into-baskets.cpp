class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l = 0  , r = 0;
        int cnt = 0;
        while(r < fruits.size()){
            while(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            cnt = max(cnt, r-l+1);
            mpp[fruits[r]]++;
            r++;
        }
        return cnt;
    }
};