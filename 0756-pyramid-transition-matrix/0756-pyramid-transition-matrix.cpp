class Solution {
public:
    unordered_map<string, vector<char>> mpp;
    unordered_map<string,bool > dp;
    bool solve(string prev, int i, string curr){
        int n = prev.size();
        if(dp.count(prev) && i == 0) return dp[prev];

        if(i == n-1){
            if(curr.size() == 1) return true;
            return dp[prev] = solve(curr, 0, "");
        }
        string s = prev.substr(i, 2);
        if(mpp.count(s)){
            for(auto& c : mpp[s]){
                curr.push_back(c);
                if(solve(prev, i+1, curr)) return true;
                curr.pop_back();
            }
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto& it : allowed) mpp[it.substr(0, 2)].push_back(it[2]);
        return solve(bottom, 0, "");
    }
};