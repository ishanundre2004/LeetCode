class Solution {
public:
    bool isBalanced(int n){
        vector<int> v(7, 0);
        
        while(n){
            if(n%10 == 0 || n%10 >= 7)return false;
            v[n%10]++;
            n/=10;
        }  
        for(int i = 1; i < 7; i++) if(v[i] != 0 && v[i] != i) return false;
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n+1; i <= 1224444; i++){
            if(isBalanced(i)) return i;
        }
        return -1;
    }
};