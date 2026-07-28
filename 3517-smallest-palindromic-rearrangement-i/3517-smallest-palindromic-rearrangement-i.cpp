class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        map<char, int> freq;
        vector<char> v;
        string s1 = "";

        for(auto& it : s) freq[it]++;

        for(auto& it : freq) s1 += string(it.second / 2, it.first);
        
        char mid;
        if (n %2 ==1) {
            for(auto &it : freq){
                
                if(it.second %2 == 1) {
                    mid = it.first;
                    break;
                }
            }
        }

        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if(n%2 == 1) s1 += mid;
        s1+=s2;
        return s1;
    }
};