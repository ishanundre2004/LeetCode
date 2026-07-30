class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(), x = n / 8;
        return (x * (x + 1) * 4) + (n % 8) * (x + 1);
    }
};