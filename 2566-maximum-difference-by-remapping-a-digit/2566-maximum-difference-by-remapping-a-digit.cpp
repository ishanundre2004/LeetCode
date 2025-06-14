class Solution {
public:
    void replace(char i,string &s){
        for(int a=0;a<s.length();a++){
            if(s[a]==i){
                s[a]='9';
            }
        }
    }
     void replace2(char i,string &str){
        for(int a=0;a<str.length();a++){
            if(str[a]==i){
                str[a]='0';
            }
        }
    }
    int minMaxDifference(int num) {
         string s=to_string(num);
         string str=to_string(num);
        for(int i=0;i<s.length();i++){
            if((int)s[i]!=57){
                replace(s[i],s);
                break;
            }
        }
        for(int i=0;i<str.length();i++){
            if((int)str[i]!=48)
            {
                
                replace2(str[i],str);
                break;
            }
        }
      
        int maxno=stoi(s);
        
        int minno=stoi(str);
        
       return maxno-minno;
    
    }
};