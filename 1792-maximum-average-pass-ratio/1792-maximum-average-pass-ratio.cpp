class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        for(int i = 0; i < n; i++){
            double c_ratio = (double)classes[i][0]/classes[i][1];
            double n_ratio = (double)(classes[i][0] + 1)/(classes[i][1] + 1);
            double diff = n_ratio - c_ratio;
            pq.push({diff, i});
        }
        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            double diff = curr.first;
            int ind = curr.second;

            classes[ind][0]++, classes[ind][1]++;
            double c_ratio = (double)classes[ind][0]/classes[ind][1];
            double n_ratio = (double)(classes[ind][0] + 1)/(classes[ind][1] + 1);

            pq.push({n_ratio-c_ratio, ind});
        }
        double result = 0.0;
        for(int i = 0; i < n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};