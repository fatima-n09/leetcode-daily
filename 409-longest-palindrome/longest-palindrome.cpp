class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        unordered_map<int,int>mp;
        for(char x:s){
            mp[x]++;
        }
        int n=s.size();
        for(auto x:mp){
            if(x.second>1){
                if (x.second % 2 == 0) {
                count += x.second;
                } else {
              count += x.second - 1;
            }

            }
        }
        if(count<n) count+=1;
        return count;

    }
};