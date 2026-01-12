class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cnt = 0, n = points.size();
        for(int i = 1 ; i < n; i++){
            int a = abs(points[i][0] - points[i-1][0]);
            int b = abs(points[i][1] - points[i-1][1]);

            if(a == b) cnt += a;
            else cnt += (min(a, b) + abs(a-b));
        }
        return cnt;
    }
};