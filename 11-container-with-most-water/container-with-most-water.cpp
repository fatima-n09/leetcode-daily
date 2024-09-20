class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        
        int curr = 0,  result = 0;
        
        while (l < r) {
            curr = (r - l) * min(heights[l], heights[r]);
            result = max(result, curr);
            
            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return result;
    }
};
