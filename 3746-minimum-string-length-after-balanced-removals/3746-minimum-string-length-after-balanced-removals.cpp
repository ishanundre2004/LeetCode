class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0;
        for(auto& c : s ) c == 'a' ? a++ : b++;
        return abs(a-b);
    }
};