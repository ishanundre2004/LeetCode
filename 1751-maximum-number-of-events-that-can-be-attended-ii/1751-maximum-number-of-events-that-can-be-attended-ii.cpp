typedef pair<int, int> pii;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for(int i = 1; i <= k; i++){
            int ma = 0;
            priority_queue<pii, vector<pii>, greater<pii>> pq;

            for(int j = 0; j < n; j++){
                while(!pq.empty() && events[j][0] > pq.top().first){
                    int index = pq.top().second;
                    ma = max(ma, dp[index][i - 1]);
                    pq.pop(); 
                }
                dp[j][i] = ma + events[j][2];
                pq.push({events[j][1], j});
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; i++)
            res = max(res, dp[i][k]);
        return res;
    }
};