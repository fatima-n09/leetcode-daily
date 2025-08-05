class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> prjt;
        for (int i = 0; i < n; ++i) {
            prjt.push_back({capital[i], profits[i]});
        }
        sort(prjt.begin(), prjt.end());
        priority_queue<int> maxProfit;
        int index = 0;
        for (int i = 0; i < k; ++i) {
            while (index < n && prjt[index].first <= w) {
                maxProfit.push(prjt[index].second);
                ++index;
            }
            if (maxProfit.empty()) break;
            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
}; 