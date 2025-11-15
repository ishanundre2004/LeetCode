class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = s.length();

        vector<int> next_zero(N, N);
        for (int i = N - 2; i >= 0; i--) next_zero[i] = (s[i + 1] == '0') ? i + 1 : next_zero[i + 1];
        int res = 0;

        for (int l = 0; l < N; l++) {
            int zeroes = (s[l] == '0') ? 1 : 0;
            int r = l;

            while (zeroes * zeroes <= N) {

                int next_z = (r < N ? next_zero[r] : N);

                int ones = (next_z - 1) - zeroes - l + 1;

                if (ones >= zeroes * zeroes) res += min(next_z - r, ones - zeroes * zeroes + 1);
                r = next_z;
                zeroes++;
                if (r == N) break;
            }
        }
        return res;
    }
};