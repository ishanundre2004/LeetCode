class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if (n < 3)
            return false;
        int vowels_count = 0, consonants_count = 0;
        std::unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U',
                                           'a', 'e', 'i', 'o', 'u'};

        unordered_set<char> consonants;
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (vowels.find(c) == vowels.end()) {
                consonants.insert(c);
            }
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (vowels.find(c) == vowels.end()) {
                consonants.insert(c);
            }
        }
        unordered_set<char> specialChars = {
            '!',  '@', '#', '$', '%', '^', '&', '*',  '(', ')', '-',
            '_',  '=', '+', '[', ']', '{', '}', '\\', '|', ';', ':',
            '\'', '"', ',', '<', '.', '>', '/', '?',  '`', '~'};

        for(auto& it : word){
            if(vowels.find(it) != vowels.end()) vowels_count++;
            if(consonants.find(it) != consonants.end()) consonants_count++;
            if(specialChars.find(it) != specialChars.end()) return false;
        }

        return (vowels_count == 0 || consonants_count == 0) ? false : true;
    }
};