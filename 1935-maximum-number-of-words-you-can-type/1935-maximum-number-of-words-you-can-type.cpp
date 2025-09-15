class Solution {
public:
    int canBeTypedWords(string text, string b) {
        unordered_set<char> s;
        for(auto& it : b){
            s.insert(it);
        }
        bool valid = true;
        int cnt = 0;
        for(int i =0 ; i < text.length(); i++){
            if(text[i] == ' '){
                if(valid) cnt++;
                valid = true;
            }else if(s.count(text[i])){
                valid = false;
            }
        }

        if(valid) cnt++;
        return cnt;

    }
};