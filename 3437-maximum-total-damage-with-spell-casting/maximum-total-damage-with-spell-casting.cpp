class Solution {
public:
    long long maximumTotalDamage(vector<int>& power){
        sort(power.begin(), power.end());
        vector<int> unique;
        vector<long long> total;
        int n = power.size();
        int i = 0;
        while (i < n) {
            int current = power[i];
            long long sum = current;
            int j = i + 1;
            while (j < n && power[j] == current){
                sum += current;
                j++;
            }
            unique.push_back(current);
            total.push_back(sum);
            i = j;
        }
        int m = unique.size();
        vector<long long> dp(m + 1, 0);
        for (int j = m - 1; j >= 0; j--) {
            long long skip = dp[j + 1];
            long long take = total[j];
            int nextIndex = j + 1;
            while (nextIndex < m && unique[nextIndex] - unique[j] <= 2){
                nextIndex++;}
            take += dp[nextIndex];
            dp[j] = max(skip, take);
        }return dp[0];
    }
};