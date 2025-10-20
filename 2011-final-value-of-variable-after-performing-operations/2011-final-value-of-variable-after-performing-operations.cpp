class Solution {
public:
    int finalValueAfterOperations(vector<string>& ops) {
        int ans = 0;
        for(auto& op : ops) ans += (op[1] == '+') ? 1 : -1;
        return ans;
    }
};