class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& it : nums){
            s.insert(it);
        }
        return (s.size() == 1) ? 0 : 1;
    }
};