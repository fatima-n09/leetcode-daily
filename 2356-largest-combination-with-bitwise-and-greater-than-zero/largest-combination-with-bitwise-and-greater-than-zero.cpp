class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;
        for (int bit = 0; bit <= 31; bit++) {
            int count = 0;

            for (int nums : candidates) {
                if ((nums & (1 << bit)) != 0) {
                    count++;
                }
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};