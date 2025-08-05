class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> roomEnd(n, 0);
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) available.push(i);
        // min-heap, {end time, room number}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
            // Free up rooms
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            if (!available.empty()) {
                int room = available.top(); available.pop();
                roomEnd[room] = end;
                count[room]++;
                busy.push({end, room});
            } else {
                auto [nextEnd, room] = busy.top(); busy.pop();
                roomEnd[room] = nextEnd + (end - start);
                count[room]++;
                busy.push({roomEnd[room], room});
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[ans]) ans = i;
        }
        return ans;
    }
}; 