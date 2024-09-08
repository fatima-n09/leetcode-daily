class Solution {
public:
    bool isPalindrome(int x)
    {
       if( x < 0) return false;
       int left = x;
       long right = 0;
       while( x > 0 )
       {
         right = right*10 +x %10;
         x /= 10;
       }
        if( left == right)
        {
            return true;
        } 
        else
        {
            return false;
        }
    }
};