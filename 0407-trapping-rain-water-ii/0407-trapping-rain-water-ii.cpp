class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < m; i++){
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            vis[i][0] = 1;
            vis[i][n - 1] = 1;
        }
        for(int j = 1; j < n - 1; j++){
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m - 1][j], {m - 1, j}});
            vis[0][j] = 1;
            vis[m - 1][j] = 1;
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int water = 0;
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int h = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0; i < 4; i++){
                int r1 = r + dx[i];
                int c1 = c + dy[i];
                if(r1 >= 0 and c1 >= 0 and r1 < m and c1 < n and !vis[r1][c1]){
                    int h1 = heightMap[r1][c1];
                    vis[r1][c1] = 1;
                    water += max(0, h - h1);
                    pq.push({max(h, h1), {r1, c1}});
                }
            }
        }
        return water;
    }
};