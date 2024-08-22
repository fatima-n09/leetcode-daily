class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(true)
        {
            slow = solve(slow);
            fast = solve(solve(fast));
            if( fast == 1)
            {
                return true;
            }
            if( slow == fast)
            {
                return false;
            }
        }
    }
    int solve(int n)
    {
        int sum = 0;
        
        while( n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};