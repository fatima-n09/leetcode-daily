class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
     {
        int count=0;
        for( char stones : stones)
        {
            for( char jewels : jewels)
            {
                if( stones == jewels)
                {
                 count++;
                 break;
                }
            }
        }
        return count;
    }
};