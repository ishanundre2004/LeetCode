class Solution {
public:
    bool isValid(string str){
        if(str.empty()) return false;
        for(auto& ch : str) if( !isalnum(ch) && ch != '_' ) return false;
        return true;
    } 
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        vector<pair<int, string>> temp;
        unordered_map<string, int> mpp {
            {"electronics" , 0},
            {"grocery" , 1}, 
            {"pharmacy" , 2}, 
            {"restaurant",  3}
        };
        for(int i = 0 ; i < code.size(); i++){
            if(isActive[i] && isValid(code[i]) && mpp.count(businessLine[i])){
                temp.push_back({mpp[businessLine[i]], code[i]});
            } 
        }
        sort(temp.begin(), temp.end());
        for(auto& it : temp) ans.push_back(it.second);
        return ans;
    }
};