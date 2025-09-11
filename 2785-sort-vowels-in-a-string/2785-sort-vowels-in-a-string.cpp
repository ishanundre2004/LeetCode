class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
         return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string sortVowels(string s) {
        vector<char> v;
        for(auto& it : s){
            if(isVowel(it)) v.push_back(it);
        }
        sort(v.begin(), v.end());
        int i = 0;
        for(int j = 0; j < s.length(); j++){
            if(isVowel(s[j])){
                s[j] = v[i];
                i++;
            }
        }
        return s;

    }
};