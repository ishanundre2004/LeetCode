class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int l = 0, h = 0 ;
        int currLen = 0, maxLen = 0;
        while(h < s.length()){
            while(freq[s[h]] > 0){
                currLen--;
                freq[s[l]]--;
                l++;
            }

            freq[s[h]]++;
            currLen++;
            maxLen = max(maxLen, currLen);
            h++;
        }
        return maxLen;
    }
};