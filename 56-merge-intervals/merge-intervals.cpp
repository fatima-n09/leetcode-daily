class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) 
        {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int> & b)
        {
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        vector<int> currentInterval = intervals[0];

        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] <= currentInterval[1])
            {
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            }
            else
            {
                result.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        result.push_back(currentInterval);
        return result;
    }
};