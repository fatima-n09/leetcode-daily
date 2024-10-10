class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int l = 0,r = num;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long square =(long long) mid * mid;
            if(square == num){
                return true;
            }
            else if (square < num){
                l = mid +1;
            }
            else {
                r = mid -1;
            }
        }

        return false;   
    }
};