class Solution {
public:
    int minCost(string c, vector<int>& v) {
        int mini = 0;
        for(int i = 0 ; i < c.size()-1; i++){
            if(c[i] == c[i+1]) {
                mini += min(v[i], v[i+1]);
                v[i+1] = max(v[i], v[i+1]);
            }
        }
        return mini;
    }
};