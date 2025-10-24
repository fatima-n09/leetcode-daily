class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) 
    {
        int n = energy.size();
        vector<int> dp(n);
        int maxEnergy = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i];
            if (i + k < n) {
                dp[i] += dp[i + k];
            }
            maxEnergy = max(maxEnergy, dp[i]);
        }
        return maxEnergy;
    }
};