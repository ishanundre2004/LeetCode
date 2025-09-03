class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), compare);

        int cnt = 0;
        for(int i = 0; i < n ; i++){
            int min_y = INT_MAX;
            for(int j = i+1; j < n; j++){
                if(points[j][1] >= points[i][1] && points[j][1] < min_y){
                    cnt++;
                    min_y = points[j][1];
                }
            }
        }
        return cnt;
    }
};