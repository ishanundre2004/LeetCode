
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0, n = events.size(), day = 1, maxday = 0, count = 0;

        for (const auto& e : events) {
            maxday = max(maxday, e[1]);
        }

        while (day <= maxday) {
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                i++;
            }

            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};