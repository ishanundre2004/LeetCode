class Solution {
public:
    int minOperations(string s) {
        int x = 27;
        for(auto& it : s) {
            if(it != 'a')
                x = min(x, it - 'a');
        }
        return  (x==27) ? 0 : 26-x;
    }
};