class Solution {
public:
    int countGoodSubstrings(string s) {
        int count  = 0;
        int n = s.size();

        for( int i = 0; i <= n-3; ++i)
        { 
            if(isValid(s[i], s[i + 1], s[i + 2]))
            {
                count++;
            }
        }
        return count;
    }
private:
   bool isValid( char a, char b, char c)
   {
    return a != b && b != c && c != a;
   }
};