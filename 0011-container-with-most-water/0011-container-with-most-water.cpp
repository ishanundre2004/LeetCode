class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n-1;
        int maxArea = 0;
        while(low<high){
            int area = min(height[low], height[high]) * (high-low);
            maxArea = max(maxArea, area);
            if (height[low] <= height[high]) low++;
            else high--;
        }
        return maxArea;
    }
};