class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if (n < 3)
            return false;
        bool isVowel = false, isConsonant = false;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (auto& it : word) {
            if (!isalnum(it))
                return false;
            if (isalpha(it)) {
                char ch = tolower(it);
                if (ch == 'a' || ch == 'e'|| ch == 'i'|| ch == 'o' || ch == 'u')
                    isVowel = true;
                else
                    isConsonant = true;
            }
        }

        return isVowel && isConsonant;
    }
};