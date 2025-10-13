class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev = "";
        vector<string> ans;

        for(int i = 0; i < words.size(); i++){
            string temp = words[i];
            sort(temp.begin(), temp.end());

            if(prev != temp || ans.empty()){
                prev = temp;
                ans.push_back(words[i]);
            }

        }
        return ans;
    }
};