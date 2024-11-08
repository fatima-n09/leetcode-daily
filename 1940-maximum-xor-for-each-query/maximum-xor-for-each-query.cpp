class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>res;
        int XOR=0, n=nums.size();
        for (auto &num:nums) XOR^=num;
        int mask= pow(2, maximumBit) - 1;
        for(int i= n-1; i>=0; i--)
        {
            res.push_back(XOR^mask);
            XOR^=nums[i];
        }
        return res;
    }
};
      