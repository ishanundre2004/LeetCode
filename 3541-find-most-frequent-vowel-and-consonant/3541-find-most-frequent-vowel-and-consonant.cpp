class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for(auto& it : s){
            freq[it]++;
        }
        int cntv = 0;
        int cntc = 0;

        for(auto& it : freq){
            int ch = it.first;
            int cnt = it.second;
            if(isVowel(ch)){
                cntv = max(cnt, cntv);
            }else{
                cntc = max(cnt, cntc);
            }
        }
        return cntc + cntv;


    }
};