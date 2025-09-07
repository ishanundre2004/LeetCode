class Solution {
public:
    vector<int> sumZero(int n) {
        int start = -1 * n/2;
        vector<int> ans;
        for(int i = start; i <= n/2; i++){
            if(n%2 == 0 && i == 0) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};