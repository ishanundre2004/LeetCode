class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
        unordered_set<int> cannotComm;
        for(int i = 0; i < f.size(); i++){
            unordered_set<int> s;
            int x = f[i][0] -  1;
            int y = f[i][1] - 1;
            for(int j = 0 ; j < l[x].size(); j++){
                s.insert(l[x][j]);
            }
            int cnt = 0;
            for(int j = 0; j < l[y].size(); j++){
                if(s.find(l[y][j]) != s.end()) cnt++;
            }

            if(cnt == 0)  {
                cannotComm.insert(x+1);
                cannotComm.insert(y+1);
            }

        }
        vector<int> v(n+1 , 0);

        for(auto& it : cannotComm){
            for(int i = 0; i < l[it-1].size(); i++){
                v[l[it-1][i]]++;
            }
        }

        int maxi = INT_MIN;

        for(auto& it : v){
            maxi = max(it, maxi);
        }

        return cannotComm.size() - maxi;
    }
};