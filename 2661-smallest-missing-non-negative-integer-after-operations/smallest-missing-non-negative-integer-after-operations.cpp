class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value){
        vector<int> freq(value, 0);
        for (int num : nums){
            int r = num % value;
            if (r < 0) r += value;
            freq[r]++;}
        for (int k = 0; ; k++){
            int r = k % value;
            if (freq[r]-- == 0){
                return k;
            }
        }
    }
};