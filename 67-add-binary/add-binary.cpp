class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string result = "";
        int i = a.size()-1;
        int j = b.size()-1;

        while( i >= 0 || j >= 0 || carry > 0)
        {
            int bitA = ( i>= 0) ? a[i] - '0' : 0;
            int bitB = ( j >= 0) ? b[j] - '0' : 0;
            
            int sum = bitA + bitB + carry;
            carry = sum / 2;
            result = char('0' + sum% 2) + result;

            i--;
            j--;
        }
        return result;
    }
};