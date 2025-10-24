class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> f(n);
        
        for (int j = 0; j < m; j++) {
            long long x = mana[j];
            long long current = f[0];
            
            for (int i = 1; i < n; i++) {
                current = max(current + 1LL * skill[i-1] * x, f[i]);
            }
            
            f[n-1] = current + 1LL * skill[n-1] * x;
            
            for (int i = n-2; i >= 0; i--) {
                f[i] = f[i+1] - 1LL * skill[i+1] * x;
            }
        }
        
        return f[n-1];
    }
};