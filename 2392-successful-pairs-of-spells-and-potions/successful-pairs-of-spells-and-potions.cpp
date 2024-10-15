class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
     sort(potions.begin(), potions.end());

        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int spell = spells[i];

            int start = 0, end = m - 1;
            int mid;

            while(start <= end) {
                mid = start + (end-start)/2;
                long long check = (long long)potions[mid] * (long long)spell;
                if(check < success) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            ans[i] = m - start;
        }

        return ans;   
    }
};