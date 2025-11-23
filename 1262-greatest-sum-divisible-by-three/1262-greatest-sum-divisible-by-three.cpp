class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> remOne, remTwo;
        int sum = 0;

        for (auto& num : nums) {
            sum += num;
            if (num % 3 == 1)
                remOne.push_back(num);
            else if (num % 3 == 2)
                remTwo.push_back(num);
        }

        sort(remOne.begin(), remOne.end());
        sort(remTwo.begin(), remTwo.end());

        if (sum % 3 == 1) {
            if (remOne.size() >= 1 && remTwo.size() >= 2) {
                int result1 = sum - remOne[0];
                int result2 = sum - remTwo[0] - remTwo[1];
                return max(result1, result2);
            } else if (remOne.size() >= 1) {
                return sum - remOne[0];
            } else if (remTwo.size() >= 2) {
                return sum - remTwo[0] - remTwo[1];
            } else {
                return 0;
            }
        }

        if (sum % 3 == 2) {
            if (remOne.size() >= 2 && remTwo.size() >= 1) {
                int result1 = sum - remOne[0] - remOne[1];
                int result2 = sum - remTwo[0];
                return max(result1, result2);
            } else if (remOne.size() >= 2) {
                return sum - remOne[0] - remOne[1];
            } else if (remTwo.size() >= 1) {
                return sum - remTwo[0];
            } else {
                return 0;
            }
        }

        return sum;
    }
};