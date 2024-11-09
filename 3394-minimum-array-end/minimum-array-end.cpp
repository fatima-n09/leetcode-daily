class Solution {
public:
    long long minEnd(int n, int x) {
        long long nums=x;
        for(int i = n - 1; i >= 1; i--)
        {
            nums=(nums+1)|x;
        }

        return nums;
    }
};