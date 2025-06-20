class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> mp;
        for (int num : answers) 
        {
            mp[num]++;
        }
        for (auto& p : mp) 
        {
            res += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        }
        return res;
    }
};