class Solution {
public:
    char kthCharacter(int k) {
        if(k == 1){
            return 'a';
        }
        int length  =1;
        while(length < k){
            length*=2;
        } 
        return helper(k, length, 'a');
    }

    char helper(int k, int length, char ch){
        if(length == 1){
            return ch;
        }

        int mid = length/2;
        if(k<=mid){
            return helper(k, mid, ch);
        }else{
            return helper(k-mid, mid, nextChar(ch));
        }
    }
    char nextChar(char ch){
        return (ch == 'z') ? 'a' : ch+1;
    }
};