class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> mpp;
        for(auto& it : meetings) mpp[it[2]].push_back({it[0], it[1]});
        vector<int> vis(n, 0);
        vis[0] = 1, vis[firstPerson] = 1;
        for(auto& it : mpp){
            unordered_map<int, vector<int>> adj;
            queue<int> q;
            unordered_set<int> s;
            for(auto& x : it.second){
                adj[x.first].push_back(x.second);
                adj[x.second].push_back(x.first);
                if(vis[x.first] && !s.count(x.first)) q.push(x.first), s.insert(x.first);
                if(vis[x.second] && !s.count(x.second)) q.push(x.second), s.insert(x.second);
            }
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto& i : adj[x]) if(!vis[i]) vis[i] = 1, q.push(i);
            }
        }
        vector<int> ans;
        for(int i = 0 ; i < n; i++) if(vis[i]) ans.push_back(i);
        return ans;
    }
};