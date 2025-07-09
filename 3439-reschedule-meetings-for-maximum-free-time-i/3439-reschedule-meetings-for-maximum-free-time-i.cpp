class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>  gaps;
        gaps.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++){
            gaps.push_back(startTime[i] - endTime[i-1]);
        }
        gaps.push_back(eventTime - endTime.back());
        int maxFree = INT_MIN;
        int currFree = 0;
        for(int i = 0; i< gaps.size(); i++){
            if(i >=  k+1){
                currFree += gaps[i] - gaps[i-k-1];
            }else{
                currFree += gaps[i];
            }
            maxFree = max(maxFree, currFree);
        }
        return maxFree;

    }
};