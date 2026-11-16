class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string temp = "";
            int x = (s.length() + k - 1) / k;
            for (int i = 0; i < x; i++) {
                int n = k * i, sum = 0;
                for (int j = n; j < min(n + k, (int)s.length()); j++) sum += s[j] - '0';
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};