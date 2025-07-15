class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto& it: s){
            if(isalpha(it)) res += it;
            else if(it == '*'){
                if(!res.empty()) res.pop_back();
                else continue;
            }
            else if(it == '#') res += res;
            else if( it == '%') reverse(res.begin(), res.end());
        }
        return res;
    }
};