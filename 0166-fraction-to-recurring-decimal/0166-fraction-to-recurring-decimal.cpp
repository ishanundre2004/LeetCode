class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string ans = "";
        if(numerator < 0 ^ denominator < 0) ans += "-";


        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        ans += to_string(n/d);
        long long rem = n % d;
        if(rem == 0) return ans;

        ans += '.';
        unordered_map<long long, int> mpp;
        while(rem != 0){
            if(mpp.count(rem)){
                ans.insert(mpp[rem], "(");
                ans += ")";
                break;
            }
            mpp[rem] = ans.length();
            rem *= 10;

            ans += to_string(rem/d);
            rem %= d;
        }
        return ans;

    }
};