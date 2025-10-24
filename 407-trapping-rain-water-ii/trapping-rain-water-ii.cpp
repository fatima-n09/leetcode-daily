struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int water = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    pq.push({i, j, heightMap[i][j]});
                    visited[i][j] = true;
                }
            }
        }
        
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int x = cell[0], y = cell[1], h = cell[2];
            
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (heightMap[nx][ny] < h) {
                        water += h - heightMap[nx][ny];
                    }
                    pq.push({nx, ny, max(heightMap[nx][ny], h)});
                }
            }
        }
        
        return water;
    }
};