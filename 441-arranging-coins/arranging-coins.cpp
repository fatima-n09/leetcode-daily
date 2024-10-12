class Solution {
public:
    int arrangeCoins(int n) 
    {
     int l=1,r = n;
     long long sum, mid;

        while(l<=r){
           mid = l + (r-l)/2;

            sum = mid * (mid+1)/2;

            if(sum==n){
                return mid;
            }
            else if(sum<n){
                l = mid  + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return r;   
    }
};