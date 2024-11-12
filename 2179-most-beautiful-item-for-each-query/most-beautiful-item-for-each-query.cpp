class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = queries.size();
        vector<pair<int, int>> queryIdx;
        for (int i = 0; i < n ; i++)
            queryIdx.push_back({queries[i], i});

        sort(queryIdx.begin(), queryIdx.end());
        vector<int> ans(queries.size());
        int maxBeauty = 0, i = 0;
        int x = items.size();
        for (auto& [query, idx] : queryIdx) {
            while (i < x && items[i][0] <= query){
                maxBeauty = max(maxBeauty, items[i][1]);
                i++;
            }    
            ans[idx] = maxBeauty;
        }

        return ans;
    }
};
