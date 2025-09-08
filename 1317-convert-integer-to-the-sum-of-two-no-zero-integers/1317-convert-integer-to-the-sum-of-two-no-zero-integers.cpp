class Solution {
public: 
    bool zero(int n){
        while(n){
            if(n%10 == 0) return true;
            n/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            if(!zero(i) && !zero(n-i)) return {i, n-i};
        }
        return {};
    }
};