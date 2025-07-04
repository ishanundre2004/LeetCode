class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
       int ops  = 0;
       while( k > 1){
            int jumps = ceil(log2(k));
            k-=pow(2, jumps-1);
            ops += operations[jumps-1];
       } 
       return char('a'+(ops%26));
    }
};
