class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());

        vector<string>result;
        result.push_back(folder[0]);
        for(int i=1;i<n;i++){
           string curr_folder = folder[i];
           string last_folder = result.back();

           last_folder+='/';

           if(curr_folder.find(last_folder) != 0){
             result.push_back(curr_folder);
           }
        }
        return result;
    }
};