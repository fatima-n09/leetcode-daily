class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0, res = 0, prev = 0;
        
        while (i < n) {
            int start = i;
            while (i + 1 < n && nums[i] < nums[i + 1]) {
                i++;
            }
            int curr = i - start + 1;
            res = max(res, max(curr >> 1, min(curr, prev)));
            prev = curr;
            i++;
         }return res;
    }
};